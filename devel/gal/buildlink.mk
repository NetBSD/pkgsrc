# $NetBSD: buildlink.mk,v 1.4 2002/09/10 16:06:38 wiz Exp $
#
# This Makefile fragment is included by packages that use gal.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gal to the dependency pattern
#     for the version of gal desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GAL_BUILDLINK_MK)
GAL_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gal?=		gal>=0.19.3nb1
DEPENDS+=	${BUILDLINK_DEPENDS.gal}:../../devel/gal

EVAL_PREFIX+=			BUILDLINK_PREFIX.gal=gal
BUILDLINK_PREFIX.gal_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gal+=		include/gal/*
BUILDLINK_FILES.gal+=		include/gal/*/*
BUILDLINK_FILES.gal+=		lib/libgal.*

.include "../../converters/libiconv/buildlink.mk"
.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"

BUILDLINK_TARGETS.gal=		gal-buildlink
BUILDLINK_TARGETS.gal+=		gal-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gal}

BUILDLINK_CONFIG.gal=		${BUILDLINK_PREFIX.gal}/lib/galConf.sh
BUILDLINK_CONFIG_WRAPPER.gal=	${BUILDLINK_DIR}/lib/galConf.sh

.if defined(USE_CONFIG_WRAPPER)
GAL_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.gal}
CONFIGURE_ENV+=		GAL_CONFIG="${GAL_CONFIG}"
MAKE_ENV+=		GAL_CONFIG="${GAL_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gal}
gal-buildlink: _BUILDLINK_USE
gal-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GAL_BUILDLINK_MK
