# $NetBSD: buildlink3.mk,v 1.8 2004/11/02 21:48:53 kristerw Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GPGME_BUILDLINK3_MK:=	${GPGME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gpgme
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngpgme}
BUILDLINK_PACKAGES+=	gpgme

.if !empty(GPGME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gpgme+=	gpgme>=0.9.0
BUILDLINK_RECOMMENDED.gpgme+=	gpgme>=1.0.1
BUILDLINK_PKGSRCDIR.gpgme?=	../../security/gpgme
.endif	# GPGME_BUILDLINK3_MK

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "SunOS"
.include "../../devel/librfuncs/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
