# $NetBSD: buildlink3.mk,v 1.1 2004/04/10 23:41:01 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_BASE_BUILDLINK3_MK:=	${GNUSTEP_BASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-base}
BUILDLINK_PACKAGES+=	gnustep-base

.if !empty(GNUSTEP_BASE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnustep-base+=	gnustep-base>=1.9.1
BUILDLINK_PKGSRCDIR.gnustep-base?=	../../devel/gnustep-base
.endif	# GNUSTEP_BASE_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ffcall/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
