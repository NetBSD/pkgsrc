# $NetBSD: buildlink.mk,v 1.3 2001/12/07 14:32:32 kei Exp $
#
# This Makefile fragment is included by packages that use bonobo.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.bonobo to the dependency pattern
#     for the version of bonobo desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(BONOBO_BUILDLINK_MK)
BONOBO_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.bonobo?=	bonobo>=1.0.9
DEPENDS+=	${BUILDLINK_DEPENDS.bonobo}:../../devel/bonobo

EVAL_PREFIX+=			BUILDLINK_PREFIX.bonobo=bonobo
BUILDLINK_PREFIX.bonobo_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.bonobo=		include/bonobo.h
BUILDLINK_FILES.bonobo+=	include/efs*
BUILDLINK_FILES.bonobo+=	include/gnome-1.0/bonobo/*
BUILDLINK_FILES.bonobo+=	lib/bonobo/*/*
BUILDLINK_FILES.bonobo+=	lib/libbonobo.*
BUILDLINK_FILES.bonobo+=	lib/libbonobox.*
BUILDLINK_FILES.bonobo+=	lib/libbonobo-print.*
BUILDLINK_FILES.bonobo+=	lib/libefs.*

CPPFLAGS+=			-I${BUILDLINK_DIR}/include/gnome-1.0

BUILDLINK_CONFIG_WRAPPER_SED+=	\
	-e "s|-I${BUILDLINK_PREFIX.bonobo}/\(include/gnome-1.0\)|-I${BUILDLINK_DIR}/\1|g"

.include "../../graphics/gdk-pixbuf-gnome/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"

BUILDLINK_TARGETS.bonobo=	bonobo-buildlink
BUILDLINK_TARGETS.bonobo+=	bonobo-buildlink-config-wrapper
BUILDLINK_TARGETS.bonobo+=	libefs-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.bonobo}

BUILDLINK_CONFIG.bonobo=		${BUILDLINK_PREFIX.bonobo}/lib/bonoboConf.sh
BUILDLINK_CONFIG_WRAPPER.bonobo=	${BUILDLINK_DIR}/lib/bonoboConf.s
BUILDLINK_CONFIG.libefs=		${BUILDLINK_PREFIX.bonobo}/bin/libefs-config
BUILDLINK_CONFIG_WRAPPER.libefs=	${BUILDLINK_DIR}/bin/libefs-config

.if defined(USE_CONFIG_WRAPPER)
BONOBO_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.bonobo}
LIBEFS_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.libefs}
CONFIGURE_ENV+=		BONOBO_CONFIG="${BONOBO_CONFIG}"
CONFIGURE_ENV+=		LIBEFS_CONFIG="${LIBEFS_CONFIG}"
MAKE_ENV+=		BONOBO_CONFIG="${BONOBO_CONFIG}"
MAKE_ENV+=		LIBEFS_CONFIG="${LIBEFS_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.bonobo}
bonobo-buildlink: _BUILDLINK_USE
bonobo-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
libefs-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# BONOBO_BUILDLINK_MK
