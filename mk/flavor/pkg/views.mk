# $NetBSD: views.mk,v 1.7 2011/09/08 20:17:16 abs Exp $

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
	@${STEP_MSG} "Building views for ${PKGNAME}"

su-build-views:
	${RUN}								\
	${MKDIR} ${LOCALBASE};						\
	for v in ${PKGVIEWS}; do					\
		case "$$v" in						\
		"")	dbdir=${PKG_DBDIR}; viewname=standard ;;	\
		*)	dbdir=${LOCALBASE}/$$v/.dbdir; viewname=$$v ;;	\
		esac;							\
		${STEP_MSG} "Performing package view clash check for ${PKGNAME} in $$viewname view"; \
		pkg=`${PKG_INFO_CMD} -K $$dbdir -e ${PKGBASE} || ${TRUE}`; \
		case "$$pkg" in						\
		"")	;;						\
		*)	${WARNING_MSG} "${PKGBASE} exists in $$viewname view - package $$pkg ***"; \
			${WARNING_MSG} "Not hoisting ${PKGNAME} into $$viewname view"; \
			continue;					\
			;;						\
		esac;							\
		${STEP_MSG} "Performing package view overwrite check for ${PKGNAME} in $$viewname view"; \
		dups=`${PKGSRC_SETENV} PLIST_IGNORE_FILES=${_PLIST_IGNORE_FILES:Q} ${PKG_VIEW} --view=$$v check ${PKGNAME} || ${TRUE}`; \
		case "$$dups" in					\
		"")	;;						\
		*)	${WARNING_MSG} "***********************************************************"; \
			${WARNING_MSG} "**** The following symbolic links will be overwritten *****"; \
			for f in $$dups; do				\
				${LS} -l ${LOCALBASE}/$$v/$$f | ${WARNING_CAT}; \
			done;						\
			${WARNING_MSG} "***********************************************************"; \
			;;						\
		esac;							\
		${STEP_MSG} "Linking package into $$viewname view";	\
		${PKGSRC_SETENV} PLIST_IGNORE_FILES=${_PLIST_IGNORE_FILES:Q} ${PKG_VIEW} --view=$$v add ${PKGNAME}; \
	done

######################################################################
### remove-views, su-remove-views (PRIVATE)
######################################################################
### remove-views removes the package from each view in PKGVIEWS.
###
.PHONY: remove-views su-remove-views
remove-views: su-target
	@${STEP_MSG} "Removing ${PKGNAME} from views"

su-remove-views:
	${RUN}								\
	for v in "" ${PKGVIEWS}; do					\
		${TEST} -n "$$v" || continue;				\
		case "$$v" in						\
		"")	dbdir=${PKG_DBDIR}; viewname=standard ;;	\
		*)	dbdir=${LOCALBASE}/$$v/.dbdir; viewname=$$v ;;	\
		esac;							\
		${STEP_MSG} "Removing package from $$viewname view";	\
		${PKGSRC_SETENV} PLIST_IGNORE_FILES=${_PLIST_IGNORE_FILES:Q} ${PKG_VIEW} --view=$$v delete ${PKGNAME}; \
	done
