# $NetBSD: buildlink.mk,v 1.1.1.1 2002/09/05 16:05:33 wiz Exp $
#
# This Makefile fragment is included by packages that use gnome-mime-data.
#
# This file was created automatically using createbuildlink 1.6.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gnome-mime-data to the dependency pattern
#     for the version of gnome-mime-data desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GNOME_MIME_DATA_BUILDLINK_MK)
GNOME_MIME_DATA_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gnome-mime-data?=		gnome-mime-data>=1.0.7
DEPENDS+=	${BUILDLINK_DEPENDS.gnome-mime-data}:../../databases/gnome-mime-data

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-mime-data=gnome-mime-data
BUILDLINK_PREFIX.gnome-mime-data_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome-mime-data+=	lib/pkgconfig/gnome-mime-data-2.0.pc

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"

BUILDLINK_TARGETS.gnome-mime-data=	gnome-mime-data-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gnome-mime-data}
BUILDLINK_TARGETS+=		${BUILDLINK_PKG_CONFIG}

pre-configure: ${BUILDLINK_TARGETS}
gnome-mime-data-buildlink: _BUILDLINK_USE

.endif	# GNOME_MIME_DATA_BUILDLINK_MK
