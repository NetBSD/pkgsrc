# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:13 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PNETLIB_BUILDLINK3_MK:=	${PNETLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pnetlib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npnetlib}
BUILDLINK_PACKAGES+=	pnetlib

.if !empty(PNETLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pnetlib+=	pnetlib>=0.6.2
BUILDLINK_PKGSRCDIR.pnetlib?=	../../lang/pnetlib
.endif	# PNETLIB_BUILDLINK3_MK

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../lang/pnet/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
