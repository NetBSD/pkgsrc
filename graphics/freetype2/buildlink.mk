# $NetBSD: buildlink.mk,v 1.13 2001/11/30 17:21:55 jlam Exp $
#
# This Makefile fragment is included by packages that use freetype2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.freetype2 to the dependency pattern
#     for the version of freetype2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(FREETYPE2_BUILDLINK_MK)
FREETYPE2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.freetype2?=	freetype2>=2.0.1

# Check if we got FreeType2 distributed with XFree86 4.x or if we need to
# depend on the freetype2 package.
#
.include "../../mk/bsd.prefs.mk"
.if exists(${X11BASE}/include/freetype2/freetype/freetype.h)
_IS_BUILTIN_FREETYPE2!=	${EGREP} -c BuildFreetype2Library ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_FREETYPE2=	0
.endif
.if ${_IS_BUILTIN_FREETYPE2} == "0"
_NEED_FREETYPE2=	YES
.else
_NEED_FREETYPE2=	NO
.endif

.if ${_NEED_FREETYPE2} == "YES"
DEPENDS+=	${BUILDLINK_DEPENDS.freetype2}:../../graphics/freetype2
EVAL_PREFIX+=	BUILDLINK_PREFIX.freetype2=freetype2
BUILDLINK_PREFIX.freetype2_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.freetype2=	${X11BASE}
.endif

BUILDLINK_FILES.freetype2=	include/ft2build.h
BUILDLINK_FILES.freetype2+=	include/freetype2/ft2build.h
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/cache/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/config/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/internal/*
BUILDLINK_FILES.freetype2+=	lib/libfreetype.*

BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.freetype2}
BUILDLINK_TARGETS.freetype2=	freetype2-buildlink

.if ${_NEED_FREETYPE2} == "YES"
BUILDLINK_TARGETS.freetype2+=		freetype2-buildlink-config-wrapper
BUILDLINK_CONFIG.freetype2=	\
			${BUILDLINK_PREFIX.freetype2}/bin/freetype-config
BUILDLINK_CONFIG_WRAPPER.freetype2=	\
			${BUILDLINK_DIR}/bin/freetype-config

freetype2-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.else
BUILDLINK_TARGETS.freetype2+=		freetype2-buildlink-config
BUILDLINK_CONFIG.freetype2=		${BUILDLINK_DIR}/bin/freetype-config
BUILDLINK_CONFIG_WRAPPER.freetype2=	${BUILDLINK_CONFIG.freetype2}

freetype2-buildlink-config:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${BUILDLINK_CONFIG.freetype2} ]; then			\
		${ECHO_BUILDLINK_MSG} "Creating config script ${BUILDLINK_CONFIG.freetype2}."; \
		${MKDIR} ${BUILDLINK_CONFIG.freetype2:H};		\
		${SED}	-e "s|@AWK@|${AWK}|g"				\
			-e "s|@SED@|${SED}|g"				\
			-e "s|@X11BASE@|${X11BASE}|g"			\
			-e "s|@BUILDLINK_DIR@|${BUILDLINK_DIR}|g"	\
			${.CURDIR}/../../graphics/freetype2/buildlink-freetype-config.in \
			> ${BUILDLINK_CONFIG.freetype2};		\
		${CHMOD} +x ${BUILDLINK_CONFIG.freetype2};		\
	fi
.endif	# _NEED_FREETYPE2

REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.freetype2}|${BUILDLINK_CONFIG.freetype2}|g"

.if defined(USE_CONFIG_WRAPPER)
FREETYPE_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.freetype2}
CONFIGURE_ENV+=		FREETYPE_CONFIG="${FREETYPE_CONFIG}"
MAKE_ENV+=		FREETYPE_CONFIG="${FREETYPE_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.freetype2}
freetype2-buildlink: _BUILDLINK_USE

.endif	# FREETYPE2_BUILDLINK_MK
