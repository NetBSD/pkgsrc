# $NetBSD: buildlink3.mk,v 1.2 2004/01/04 23:34:06 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GD_BUILDLINK3_MK:=	${GD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gd
.endif

.if !empty(GD_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		gd
BUILDLINK_DEPENDS.gd?=		gd>=2.0.15
BUILDLINK_PKGSRCDIR.gd?=	../../graphics/gd

.  include "../../devel/zlib/buildlink3.mk"
.  include "../../graphics/freetype2/buildlink3.mk"
.  include "../../graphics/jpeg/buildlink3.mk"
.  include "../../graphics/png/buildlink3.mk"
.  include "../../graphics/xpm/buildlink3.mk"
.endif	# GD_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
