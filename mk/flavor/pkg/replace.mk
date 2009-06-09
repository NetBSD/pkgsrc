# $NetBSD: replace.mk,v 1.25 2009/06/09 08:40:27 joerg Exp $
#

# _flavor-replace:
#	Updates a package in-place on the system (USE_DESTDIR=yes).
#
# _flavor-destdir-replace:
#	Updates a package in-place on the system (USE_DESTDIR=yes).
#
# See also:
#	replace
#
# XXX: The whole replacement, from deinstalling the old package up
# to installing the new package, should be one transaction. It
# currently isn't, and the check-files target for other packages
# can be confused when a +REQUIRED_BY files suddenly disappears.
#
_flavor-replace: \
	replace-names \
	replace-tarup \
	replace-preserve-installed-info \
	replace-preserve-required-by \
	deinstall \
	install-clean \
	install \
	replace-fixup-required-by \
	replace-fixup-installed-info \
	.PHONY

_flavor-destdir-replace: \
	replace-names \
	replace-destdir \
	replace-fixup-required-by \
	replace-fixup-installed-info \
	.PHONY

# _flavor-undo-replace:
#	Undoes the actions from a previous _flavor-replace.
#
# See also:
#	undo-replace
#
_flavor-undo-replace: \
	undo-replace-check \
	replace-preserve-installed-info \
	replace-preserve-required-by \
	deinstall \
	undo-replace-install \
	replace-fixup-required-by \
	replace-clean \
	.PHONY

_INSTALLED_INFO_FILE=	${WRKDIR}/.replace-+INSTALLED_INFO
_REQUIRED_BY_FILE=	${WRKDIR}/.replace-+REQUIRED_BY

_COOKIE.replace=	${WRKDIR}/.replace_done
_REPLACE_OLDNAME_FILE=	${WRKDIR}/.replace_oldname
_REPLACE_NEWNAME_FILE=	${WRKDIR}/.replace_newname

_REPLACE_OLDNAME_CMD=	\
	[ -f ${_REPLACE_OLDNAME_FILE} ] \
	|| ${FAIL_MSG} "[${.TARGET}] ${_REPLACE_OLDNAME_FILE}: File not found"; \
	oldname=`${CAT} ${_REPLACE_OLDNAME_FILE}`

_REPLACE_NEWNAME_CMD=	\
	[ -f ${_REPLACE_NEWNAME_FILE} ] \
	|| ${FAIL_MSG} "[${.TARGET}] ${_REPLACE_NEWNAME_FILE}: File not found"; \
	newname=`${CAT} ${_REPLACE_NEWNAME_FILE}`

# Verifies that there was a previous "replace" action performed that can be undone.
#
undo-replace-check: .PHONY
	${RUN} [ -f ${_COOKIE.replace} ] \
	|| ${FAIL_MSG} "No replacement to undo!"

# Generates a binary package for the (older) installed package using pkg_tarup.
#
replace-tarup: .PHONY
	${RUN} [ -x ${_PKG_TARUP_CMD:Q} ] \
	|| ${FAIL_MSG} ${_PKG_TARUP_CMD:Q}" was not found.";		\
	${_REPLACE_OLDNAME_CMD};					\
	${SETENV} PKG_DBDIR=${_PKG_DBDIR} PKG_SUFX=${PKG_SUFX}		\
		PKGREPOSITORY=${WRKDIR}					\
		${_PKG_TARUP_CMD} $${oldname} ||			\
	${FAIL_MSG} "Could not pkg_tarup $${oldname}".

# Re-installs the old package that has been saved by replace-tarup.
#
undo-replace-install: .PHONY
	@${PHASE_MSG} "Re-adding ${PKGNAME} from saved tar-up package."
	${RUN} ${_REPLACE_OLDNAME_CMD};					\
	${ECHO} "Installing saved package ${WRKDIR}/$${oldname}${PKG_SUFX}"; \
	${PKG_ADD} ${WRKDIR}/$${oldname}${PKG_SUFX}

# Computes and saves the full names of the installed package to be replaced
# (oldname) and the package that will be installed (newname), so that these
# names are available later.
#
replace-names: .PHONY
	${RUN} if [ x"${OLDNAME}" = x ]; then				\
		wildcard=${PKGWILDCARD:Q};				\
	else								\
		wildcard="${OLDNAME}-[0-9]*";				\
	fi;								\
	${_PKG_BEST_EXISTS} "$${wildcard}" > ${_REPLACE_OLDNAME_FILE}
	${RUN} ${ECHO} ${PKGNAME} > ${_REPLACE_NEWNAME_FILE}
	${RUN} ${CP} -f ${_REPLACE_NEWNAME_FILE} ${_COOKIE.replace}

# Saves and removes the +INSTALLED_INFO file from the installed package.
#
replace-preserve-installed-info: .PHONY
	@${STEP_MSG} "Preserving existing +INSTALLED_INFO file."
	${RUN} ${_REPLACE_OLDNAME_CMD};					\
	installed_info="${_PKG_DBDIR}/$$oldname/+INSTALLED_INFO";	\
	${TEST} ! -f "$$installed_info" ||				\
	${MV} $$installed_info ${_INSTALLED_INFO_FILE}

# Saves and removes the +REQUIRED_BY file from the installed package.
#
replace-preserve-required-by: .PHONY
	@${STEP_MSG} "Preserving existing +REQUIRED_BY file."
	${RUN} ${_REPLACE_OLDNAME_CMD};					\
	required_by="${_PKG_DBDIR}/$$oldname/+REQUIRED_BY";		\
	${TEST} ! -f "$$required_by" ||					\
	${MV} $$required_by ${_REQUIRED_BY_FILE}

# Fixes the +CONTENTS files of dependent packages to refer to the
# replacement package, and puts the +REQUIRED_BY file back into place.
# It also sets the unsafe_depends_strict tag on each dependent package,
# and sets the unsafe_depends tag if the replaced package has a different
# version.
#
# XXX Only set unsafe_depends if there is an ABI change.
#
replace-fixup-required-by: .PHONY
	@${STEP_MSG} "Fixing @pkgdep entries in dependent packages."
	${RUN} ${_REPLACE_OLDNAME_CMD};					\
	${_REPLACE_NEWNAME_CMD};					\
	${TEST} -f ${_REQUIRED_BY_FILE} || exit 0;			\
	${CAT} ${_REQUIRED_BY_FILE} |					\
	while read pkg; do						\
		case $$pkg in						\
		"")	continue ;;					\
		/*)	pkgdir="$$pkg" ;;				\
		*)	pkgdir="${_PKG_DBDIR}/$$pkg" ;;			\
		esac;							\
		contents="$$pkgdir/+CONTENTS";				\
		newcontents="$$contents.$$$$";				\
		${SETENV} OLDNAME="$$oldname" NEWNAME="$$newname"	\
		${AWK} '($$0 ~ "^@pkgdep " ENVIRON["OLDNAME"])		\
			{ print "@pkgdep " ENVIRON["NEWNAME"]; next }	\
			{ print }'					\
			$$contents > $$newcontents;			\
		${MV} -f $$newcontents $$contents;			\
		${PKG_ADMIN} set unsafe_depends_strict=YES $$pkg;	\
		if ${TEST} "$$oldname" != "$$newname"; then		\
			${PKG_ADMIN} set unsafe_depends=YES $$pkg;	\
		fi;							\
	done;								\
	${MV} ${_REQUIRED_BY_FILE} ${_PKG_DBDIR}/$$newname/+REQUIRED_BY

# Removes unsafe_depends* and rebuild tags from this package.
#
# XXX: pkg_admin should not complain on unset with no +INSTALLED_INFO.
#
replace-fixup-installed-info: .PHONY
	@${STEP_MSG} "Removing unsafe_depends and rebuild tags."
	${RUN} ${_REPLACE_NEWNAME_CMD};					\
	[ ! -f ${_INSTALLED_INFO_FILE} ] ||			\
	${MV} ${_INSTALLED_INFO_FILE} ${_PKG_DBDIR}/$$newname/+INSTALLED_INFO; \
	for var in unsafe_depends unsafe_depends_strict rebuild; do	\
		${TEST} ! -f ${_PKG_DBDIR}/$$newname/+INSTALLED_INFO || \
		${PKG_ADMIN} unset $$var $$newname;			\
	done

# Removes the state files for the "replace" target, so that it may be re-invoked.
#
replace-clean: .PHONY
	${RUN} ${_REPLACE_OLDNAME_CMD};					\
	${_REPLACE_NEWNAME_CMD};					\
	${RM} -f ${WRKDIR}/$$oldname${PKG_SUFX};			\
	${RM} -f ${WRKDIR}/$$newname${PKG_SUFX};			\
	${RM} -f ${_REPLACE_OLDNAME_FILE} ${_REPLACE_NEWNAME_FILE}	\
		${_COOKIE.replace}

replace-destdir: .PHONY
	@${PHASE_MSG} "Updating using binary package of "${PKGNAME:Q}
.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
	@${MKDIR} ${_CROSS_DESTDIR}${PREFIX}
	${PKG_ADD} -u -m ${MACHINE_ARCH} -I -p ${_CROSS_DESTDIR}${PREFIX} ${PKGFILE}
	@${ECHO} "Fixing recorded cwd..."
	@${SED} -e 's|@cwd ${_CROSS_DESTDIR}|@cwd |' ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS > ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS.tmp
	@${MV} ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS.tmp ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS
.else
	${PKG_ADD} -u ${PKGFILE}
.endif
