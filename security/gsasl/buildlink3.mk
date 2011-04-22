# $NetBSD: buildlink3.mk,v 1.14 2011/04/22 13:42:05 obache Exp $

BUILDLINK_TREE+=	gsasl

.if !defined(GSASL_BUILDLINK3_MK)
GSASL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsasl+=	gsasl>=0.2.15
BUILDLINK_ABI_DEPENDS.gsasl?=	gsasl>=1.6.0nb1
BUILDLINK_PKGSRCDIR.gsasl?=	../../security/gsasl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libntlm/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.endif # GSASL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsasl
