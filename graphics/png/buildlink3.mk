# $NetBSD: buildlink3.mk,v 1.2 2004/01/04 23:34:06 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PNG_BUILDLINK3_MK:=	${PNG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	png
.endif

.if !empty(PNG_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		png
BUILDLINK_DEPENDS.png?=		png>=1.2.4
BUILDLINK_PKGSRCDIR.png?=	../../graphics/png

.  include "../../devel/zlib/buildlink3.mk"
.endif	# PNG_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
