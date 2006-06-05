# $NetBSD: views.mk,v 1.2 2006/06/05 22:49:44 jlam Exp $

# By default, all packages attempt to link into the views.
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
BUILD_VIEWS?=	yes
.endif

# DEFAULT_VIEW.${PKGBASE}	default view for ${PKGBASE}
# VIEWBASE			base location of files at run-time
#
DEFAULT_VIEW.${PKGBASE}?=	${DEFAULT_VIEW}
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
.  if empty(DEFAULT_VIEW.${PKGBASE}:M"")
VIEWBASE=	${LOCALBASE}/${DEFAULT_VIEW.${PKGBASE}}
.  else
VIEWBASE=	${LOCALBASE}
.  endif
.elif ${PKG_INSTALLATION_TYPE} == "overwrite"
VIEWBASE=	${PREFIX}
.endif
MAKE_ENV+=	VIEWBASE=${VIEWBASE}

PKGVIEWS+=	${DEFAULT_VIEW.${PKGBASE}}

.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
privileged-install-hook: build-views
.endif

######################################################################
### build-views, su-build-views (PRIVATE)
######################################################################
### build-views adds the package to each view in PKGVIEWS.
###
.PHONY: build-views su-build-views
build-views: su-target
	@${PHASE_MSG} "Building views for ${PKGNAME}"

su-build-views:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${MKDIR} ${LOCALBASE};						\
	for v in "" ${PKGVIEWS}; do					\
		${TEST} -n "$$v" || continue;				\
		case "$$v" in						\
		"")	dbdir=${PKG_DBDIR}; viewname=standard ;;	\
		*)	dbdir=${LOCALBASE}/$$v/.dbdir; viewname=$$v ;;	\
		esac;							\
		${ECHO} "=> Performing package view clash check for ${PKGNAME} in $$viewname view"; \
		pkg=`${PKG_INFO_CMD} -K $$dbdir -e ${PKGBASE} || ${TRUE}`; \
		case "$$pkg" in						\
		"")	;;						\
		*)	${ECHO} "*** ${PKGBASE} exists in $$viewname view - package $$pkg ***"; \
			${ECHO} "*** Not hoisting ${PKGNAME} into $$viewname view"; \
			continue;					\
			;;						\
		esac;							\
		${ECHO} "=> Performing package view overwrite check for ${PKGNAME} in $$viewname view"; \
		dups=`${SETENV} PLIST_IGNORE_FILES=${_PLIST_IGNORE_FILES:Q} ${PKG_VIEW} --view=$$v check ${PKGNAME} || ${TRUE}`; \
		case "$$dups" in					\
		"")	;;						\
		*)	${ECHO} "***********************************************************"; \
			${ECHO} "**** The following symbolic links will be overwritten *****"; \
			for f in $$dups; do				\
				${LS} -l ${LOCALBASE}/$$v/$$f;		\
			done;						\
			${ECHO} "***********************************************************"; \
			;;						\
		esac;							\
		${ECHO} "=> Linking package into $$viewname view";	\
		${SETENV} PLIST_IGNORE_FILES=${_PLIST_IGNORE_FILES:Q} ${PKG_VIEW} --view=$$v add ${PKGNAME}; \
	done

######################################################################
### remove-views, su-remove-views (PRIVATE)
######################################################################
### remove-views removes the package from each view in PKGVIEWS.
###
.PHONY: remove-views su-remove-views
remove-views: su-target
	@${PHASE_MSG} "Removing ${PKGNAME} from views"

su-remove-views:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for v in "" ${PKGVIEWS}; do					\
		${TEST} -n "$$v" || continue;				\
		case "$$v" in						\
		"")	dbdir=${PKG_DBDIR}; viewname=standard ;;	\
		*)	dbdir=${LOCALBASE}/$$v/.dbdir; viewname=$$v ;;	\
		esac;							\
		${ECHO} "=> Removing package from $$viewname view";	\
		${SETENV} PLIST_IGNORE_FILES=${_PLIST_IGNORE_FILES:Q} ${PKG_VIEW} --view=$$v delete ${PKGNAME}; \
	done
