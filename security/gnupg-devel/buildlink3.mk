# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:32 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUPG_DEVEL_BUILDLINK3_MK:=	${GNUPG_DEVEL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnupg-devel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnupg-devel}
BUILDLINK_PACKAGES+=	gnupg-devel

.if !empty(GNUPG_DEVEL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnupg-devel+=	gnupg-devel>=1.9.11
BUILDLINK_ABI_DEPENDS.gnupg-devel+=	gnupg-devel>=1.9.20nb1
BUILDLINK_PKGSRCDIR.gnupg-devel?=	../../security/gnupg-devel
.endif	# GNUPG_DEVEL_BUILDLINK3_MK
BUILDLINK_PREFIX.gnupg-devel?=	${LOCALBASE}

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
