# $NetBSD: buildlink3.mk,v 1.14 2006/07/08 23:11:06 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GPGME_BUILDLINK3_MK:=	${GPGME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gpgme
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngpgme}
BUILDLINK_PACKAGES+=	gpgme
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gpgme

.if !empty(GPGME_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=0.9.0
BUILDLINK_ABI_DEPENDS.gpgme+=	gpgme>=1.0.3nb1
BUILDLINK_PKGSRCDIR.gpgme?=	../../security/gpgme
.endif	# GPGME_BUILDLINK3_MK

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../devel/librfuncs/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
