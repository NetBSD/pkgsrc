# $NetBSD: buildlink3.mk,v 1.1 2004/02/12 23:53:09 seb Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBTAR_BUILDLINK3_MK:=	${LIBTAR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtar
.endif

.if !empty(LIBTAR_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libtar
BUILDLINK_DEPENDS.libtar+=		libtar>=1.2.11
BUILDLINK_PKGSRCDIR.libtar?=		../../devel/libtar

.include "../../devel/zlib/buildlink3.mk"

.endif # LIBTAR_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
