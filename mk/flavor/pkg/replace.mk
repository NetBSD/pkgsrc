# $NetBSD: replace.mk,v 1.6 2006/11/16 22:06:18 rillig Exp $

######################################################################
### replace-pkg (PRIVATE, pkgsrc/mk/install/replace.mk)
######################################################################
### replace-pkg updates a package in-place on the system.
###

replace-pkg: \
	replace-tarup \
	replace-names \
	replace-preserve-required-by \
	deinstall \
	install-clean \
	install \
	replace-fixup-required-by \
	.PHONY

######################################################################
### undo-replace-pkg (PRIVATE, pkgsrc/mk/install/replace.mk)
######################################################################
### undo-replace-pkg undoes a "make replace".
###

undo-replace-pkg: \
	undo-replace-check \
	replace-preserve-required-by \
	deinstall \
	undo-replace-install \
	replace-fixup-required-by \
	replace-clean \
	.PHONY

_REQUIRED_BY_FILE=	${PKG_DB_TMPDIR}/+REQUIRED_BY

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
### packages to refer to the replacement package.
###
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
		${PKG_ADMIN} set unsafe_depends=YES $$pkg;		\
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
