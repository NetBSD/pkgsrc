# $NetBSD: buildlink3.mk,v 1.6 2006/06/23 12:28:55 shannonjr Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUPG_DEVEL_BUILDLINK3_MK:=	${GNUPG_DEVEL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnupg-devel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnupg-devel}
BUILDLINK_PACKAGES+=	gnupg-devel

.if ${GNUPG_DEVEL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnupg-devel+=	gnupg-devel>=1.9.20nb2
BUILDLINK_PKGSRCDIR.gnupg-devel?=	../../security/gnupg-devel
.endif	# GNUPG_DEVEL_BUILDLINK3_MK

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
