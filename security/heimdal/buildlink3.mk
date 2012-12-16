# $NetBSD: buildlink3.mk,v 1.41 2012/12/16 01:52:32 obache Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	heimdal

.if !defined(HEIMDAL_BUILDLINK3_MK)
HEIMDAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.heimdal+=	heimdal>=0.4e
BUILDLINK_ABI_DEPENDS.heimdal+=	heimdal>=1.5.2nb5
BUILDLINK_PKGSRCDIR.heimdal?=	../../security/heimdal
BUILDLINK_INCDIRS.heimdal?=	include/krb5

pkgbase := heimdal
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.heimdal:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"

CHECK_BUILTIN.heimdal:=	yes
.include "../../security/heimdal/builtin.mk"
CHECK_BUILTIN.heimdal:=	no
.if !empty(USE_BUILTIN.heimdal:M[nN][oO])
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.endif
.endif # HEIMDAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-heimdal
