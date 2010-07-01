# $NetBSD: buildlink3.mk,v 1.37 2010/07/01 18:14:19 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	heimdal

.if !defined(HEIMDAL_BUILDLINK3_MK)
HEIMDAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.heimdal+=	heimdal>=0.4e
BUILDLINK_ABI_DEPENDS.heimdal+=	heimdal>=1.1nb4
BUILDLINK_PKGSRCDIR.heimdal?=	../../security/heimdal
BUILDLINK_INCDIRS.heimdal?=	include/krb5

pkgbase := heimdal
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.heimdal:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"

.include "../../security/heimdal/builtin.mk"
.if !empty(USE_BUILTIN.heimdal:M[nN][oO])
.include "../../mk/bdb.buildlink3.mk"
.endif
.endif # HEIMDAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-heimdal
