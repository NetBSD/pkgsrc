# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/02/03 12:31:35 recht Exp $
#

.if !defined(LIBGDIPLUS_BUILDLINK2_MK)
LIBGDIPLUS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgdiplus
BUILDLINK_DEPENDS.libgdiplus?=		libgdiplus>=0.1
BUILDLINK_PKGSRCDIR.libgdiplus?=		../../graphics/libgdiplus

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgdiplus=libgdiplus
BUILDLINK_PREFIX.libgdiplus_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgdiplus+=	lib/libgdiplus.*

.include "../../graphics/cairo/buildlink2.mk"
.include "../../lang/mono/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"

BUILDLINK_TARGETS+=	libgdiplus-buildlink

libgdiplus-buildlink: _BUILDLINK_USE

.endif	# LIBGDIPLUS_BUILDLINK2_MK
