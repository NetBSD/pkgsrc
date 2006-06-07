# $NetBSD: install.mk,v 1.4 2006/06/07 17:09:52 ghen Exp $

######################################################################
### install-check-conflicts (PRIVATE, pkgsrc/mk/install/install.mk)
######################################################################
### install-check-conflicts checks for conflicts between the package
### and and installed packages.
###
.PHONY: install-check-conflicts
install-check-conflicts:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${WRKDIR}/.CONFLICTS
.for _conflict_ in ${CONFLICTS}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${_PKG_BEST_EXISTS} ${_conflict_:Q} || ${TRUE}`";	\
	case "$$found" in						\
	"")	;;							\
	*)	${ECHO} "$$found" >> ${WRKDIR}/.CONFLICTS ;;		\
	esac
.endfor
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} -f ${WRKDIR}/.CONFLICTS || exit 0;			\
	${ERROR_MSG} "${PKGNAME} conflicts with installed package(s):";	\
	while read line; do ${ERROR_MSG} "	$$line";	done	\
		< ${WRKDIR}/.CONFLICTS;					\
	${ERROR_MSG} "They install the same files into the same place."; \
	${ERROR_MSG} "Please remove conflicts first with pkg_delete(1)."; \
	${RM} -f ${WRKDIR}/.CONFLICTS;					\
	exit 1

######################################################################
### install-check-installed (PRIVATE, pkgsrc/mk/install/install.mk)
######################################################################
### install-check-installed checks if the package (perhaps an older
### version) is already installed on the system.
###
.PHONY: install-check-installed
install-check-installed:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${_PKG_BEST_EXISTS} ${PKGWILDCARD:Q} || ${TRUE}`";	\
	case "$$found" in						\
	"")	;;							\
	*)	${ERROR_MSG} "$$found is already installed - perhaps an older version?"; \
		${ERROR_MSG} "If so, you may use either of:";	\
		${ERROR_MSG} "    - \"pkg_delete $$found\" and \"${MAKE} reinstall\""; \
		${ERROR_MSG} "      to upgrade properly"; \
		${ERROR_MSG} "    - \"${MAKE} update\" to rebuild the package and all"; \
		${ERROR_MSG} "      of its dependencies"; \
		${ERROR_MSG} "    - \"${MAKE} replace\" to replace only the package without"; \
		${ERROR_MSG} "      re-linking dependencies, risking various problems."; \
		exit 1;							\
		;;							\
	esac

######################################################################
### register-pkg (PRIVATE, pkgsrc/mk/install/install.mk)
######################################################################
### register-pkg populates the package database with the appropriate
### entries to register the package as being installed on the system.
###
_REGISTER_DEPENDENCIES=							\
	${SETENV} PKG_DBDIR=${_PKG_DBDIR:Q}				\
		AWK=${TOOLS_AWK:Q}					\
		PKG_ADMIN=${PKG_ADMIN_CMD:Q}				\
	${SH} ${PKGSRCDIR}/mk/flavor/pkg/register-dependencies

.PHONY: register-pkg
register-pkg: generate-metadata ${_DEPENDS_COOKIE}
	@${PHASE_MSG} "Registering installation for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -fr ${_PKG_DBDIR}/${PKGNAME}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${_PKG_DBDIR}/${PKGNAME}
	${_PKG_SILENT}${_PKG_DEBUG}${CP} ${PKG_DB_TMPDIR}/* ${_PKG_DBDIR}/${PKGNAME}
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_ADMIN} add ${PKGNAME}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	case ${_AUTOMATIC:Q}"" in					\
	[yY][eE][sS])	${PKG_ADMIN} set automatic=yes ${PKGNAME} ;;	\
	esac
	${_PKG_SILENT}${_PKG_DEBUG}${_DEPENDS_PATTERNS_CMD} |		\
		${SORT} -u | ${_REGISTER_DEPENDENCIES} ${PKGNAME}
