# $NetBSD: buildlink2.mk,v 1.4 2004/04/05 18:41:14 wiz Exp $
#
# This Makefile fragment is included by packages that use xine-lib.
#

.if !defined(XINE_LIB_BUILDLINK2_MK)
XINE_LIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xine-lib
BUILDLINK_DEPENDS.xine-lib?=		xine-lib>=1rc3bnb1
BUILDLINK_PKGSRCDIR.xine-lib?=		../../multimedia/xine-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.xine-lib=xine-lib
BUILDLINK_PREFIX.xine-lib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xine-lib+=	include/xine.h
BUILDLINK_FILES.xine-lib+=	include/xine/*.h
BUILDLINK_FILES.xine-lib+=	lib/libxine.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/flac/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

BUILDLINK_TARGETS+=	xine-lib-buildlink

xine-lib-buildlink: _BUILDLINK_USE

.endif	# XINE_LIB_BUILDLINK2_MK
