# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:09:43 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBTABE_BUILDLINK3_MK:=	${LIBTABE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtabe
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtabe}
BUILDLINK_PACKAGES+=	libtabe

.if !empty(LIBTABE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libtabe+=	libtabe>=0.2.5
BUILDLINK_RECOMMENDED.libtabe+=	libtabe>=0.2.5nb2
BUILDLINK_PKGSRCDIR.libtabe?=	../../inputmethod/libtabe
.endif	# LIBTABE_BUILDLINK3_MK

.include "../../databases/db3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
