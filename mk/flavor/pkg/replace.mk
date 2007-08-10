# $NetBSD: replace.mk,v 1.15 2007/08/10 17:57:28 gdt Exp $
#

# _flavor-replace:
#	Updates a package in-place on the system.
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
	replace-tarup \
	replace-names \
	replace-preserve-installed-info \
	replace-preserve-required-by \
	deinstall \
	install-clean \
	install \
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

######################################################################
### undo-replace-check (PRIVATE)
######################################################################
### undo-replace-check verifies that there was a previous "replace"
### action performed that can be undone.
###
undo-replace-check: .PHONY
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} ! -f ${_COOKIE.replace} || exit 0;			\
	${ERROR_MSG} "No replacement to undo!";				\
	exit 1

######################################################################
### replace-tarup (PRIVATE)
######################################################################
### replace-tarup generates a binary package for the (older) installed
### package using pkg_tarup.
###
replace-tarup: .PHONY
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ${TEST} ! -x ${_PKG_TARUP_CMD:Q}; then			\
		${ERROR_MSG} ${_PKG_TARUP_CMD:Q}" was not found.";	\
		exit 1;							\
	fi;								\
	${SETENV} PKG_DBDIR=${_PKG_DBDIR} PKG_SUFX=${PKG_SUFX}		\
		PKGREPOSITORY=${WRKDIR}					\
		${_PKG_TARUP_CMD} ${PKGBASE}

######################################################################
### undo-replace-install (PRIVATE)
######################################################################
### undo-replace-install re-installs the old package from the binary
### package saved from replace-tarup.
###
undo-replace-install: .PHONY
	@${PHASE_MSG} "Re-adding ${PKGNAME} from saved tar-up package."
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} -f ${_REPLACE_OLDNAME_FILE} || exit 0;			\
	oldname=`${CAT} ${_REPLACE_OLDNAME_FILE}`;			\
	${ECHO} "Running ${PKG_ADD} ${WRKDIR}/$${oldname}${PKG_SUFX}";	\
	${PKG_ADD} ${WRKDIR}/$${oldname}${PKG_SUFX}

######################################################################
### replace-names, undo-replace-names (PRIVATE)
######################################################################
### replace-names and undo-replace-names save the correct names of the
### installed and replacement packages into files queried by other
### targets.
###
replace-names: .PHONY
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${_PKG_BEST_EXISTS} ${PKGWILDCARD:Q} > ${_REPLACE_OLDNAME_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} ${PKGNAME} > ${_REPLACE_NEWNAME_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CP} -f ${_REPLACE_NEWNAME_FILE} ${_COOKIE.replace}

######################################################################
### replace-preserve-installed-info (PRIVATE)
######################################################################
### replace-preserve-installed-info saves and removes the +INSTALLED_INFO
### file from the installed package.
###
replace-preserve-installed-info: .PHONY
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} -f ${_REPLACE_OLDNAME_FILE} || exit 0;			\
	${STEP_MSG} "Preserving existing +INSTALLED_INFO file.";	\
	oldname=`${CAT} ${_REPLACE_OLDNAME_FILE}`;			\
	installed_info="${_PKG_DBDIR}/$$oldname/+INSTALLED_INFO";	\
	${TEST} ! -f "$$installed_info" ||				\
	${MV} $$installed_info ${_INSTALLED_INFO_FILE}

######################################################################
### replace-preserve-required-by (PRIVATE)
######################################################################
### replace-preserve-required-by saves and removes the +REQUIRED_BY
### file from the installed package.
###
replace-preserve-required-by: .PHONY
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} -f ${_REPLACE_OLDNAME_FILE} || exit 0;			\
	${STEP_MSG} "Preserving existing +REQUIRED_BY file.";		\
	oldname=`${CAT} ${_REPLACE_OLDNAME_FILE}`;			\
	required_by="${_PKG_DBDIR}/$$oldname/+REQUIRED_BY";		\
	${TEST} ! -f "$$required_by" ||					\
	${MV} $$required_by ${_REQUIRED_BY_FILE}

######################################################################
### replace-fixup-required-by (PRIVATE)
######################################################################
### replace-fixup-required-by fixes the +CONTENTS files of dependent
### packages to refer to the replacement package, and puts the
### +REQUIRED_BY file back into place.  It also sets the
### unsafe_depends_strict tag on each dependent package, and sets the
### unsafe_depends tag if the replaced package has a different
### version.
### XXX Only set unsafe_depends if there is an ABI change.
replace-fixup-required-by: .PHONY
	@${STEP_MSG} "Fixing @pkgdep entries in dependent packages."
	${_PKG_SILENT}${_PKG_DEBUG}					\
	set -e;								\
	${TEST} -f ${_REPLACE_OLDNAME_FILE} || exit 0;			\
	${TEST} -f ${_REPLACE_NEWNAME_FILE} || exit 0;			\
	${TEST} -f ${_REQUIRED_BY_FILE} || exit 0;			\
	oldname=`${CAT} ${_REPLACE_OLDNAME_FILE}`;			\
	newname=`${CAT} ${_REPLACE_NEWNAME_FILE}`;			\
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
	${MV} ${_REQUIRED_BY_FILE} ${_PKG_DBDIR}/${PKGNAME}/+REQUIRED_BY

######################################################################
### replace-fixup-installed-info (PRIVATE)
######################################################################
### replace-fixup-installed-info removes unsafe_depends* and rebuild
### tags from this package.
### XXX pkg_admin should not complain on unset with no +INSTALLED_INFO.
replace-fixup-installed-info: .PHONY
	@${STEP_MSG} "Removing unsafe_depends tag."
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} ! -f ${_INSTALLED_INFO_FILE} ||
	${MV} ${_INSTALLED_INFO_FILE} ${_PKG_DBDIR}/${PKGNAME}/+INSTALLED_INFO; \
	for var in unsafe_depends unsafe_depends_strict rebuild; do	\
		${TEST} ! -f ${_PKG_DBDIR}/${PKGNAME}/+INSTALLED_INFO || \
		${PKG_ADMIN} unset $$var ${PKGBASE};			\
	done

######################################################################
### replace-clean (PRIVATE)
######################################################################
### replace-clean removes the state files for the "replace" target so
### that it may be re-invoked.
###
replace-clean: .PHONY
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} -f ${_REPLACE_OLDNAME_FILE} || exit 0;			\
	oldname=`${CAT} ${_REPLACE_OLDNAME_FILE}`;			\
	${RM} -f ${WRKDIR}/$$oldname${PKG_SUFX}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} -f ${_REPLACE_NEWNAME_FILE} || exit 0;			\
	newname=`${CAT} ${_REPLACE_NEWNAME_FILE}`;			\
	${RM} -f ${WRKDIR}/$$newname${PKG_SUFX}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RM} -f ${_REPLACE_OLDNAME_FILE} ${_REPLACE_NEWNAME_FILE}	\
		${_COOKIE.replace}
