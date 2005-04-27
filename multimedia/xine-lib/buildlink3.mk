# $NetBSD: buildlink3.mk,v 1.10 2005/04/27 02:40:07 salo Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XINE_LIB_BUILDLINK3_MK:=	${XINE_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xine-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxine-lib}
BUILDLINK_PACKAGES+=	xine-lib

.if !empty(XINE_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xine-lib+=	xine-lib>=1rc3c
BUILDLINK_RECOMMENDED.xine-lib+=xine-lib>=1.0nb2
BUILDLINK_PKGSRCDIR.xine-lib?=	../../multimedia/xine-lib
.endif	# XINE_LIB_BUILDLINK3_MK

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
