# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/02/16 18:38:41 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBASSETML_BUILDLINK3_MK:=	${LIBASSETML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libassetml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibassetml}
BUILDLINK_PACKAGES+=	libassetml

.if !empty(LIBASSETML_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libassetml+=	libassetml>=1.2.1
BUILDLINK_PKGSRCDIR.libassetml?=	../../multimedia/libassetml
.endif	# LIBASSETML_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
