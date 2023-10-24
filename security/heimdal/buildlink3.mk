# $NetBSD: buildlink3.mk,v 1.73 2023/10/24 22:10:48 wiz Exp $

BUILDLINK_TREE+=	heimdal

.if !defined(HEIMDAL_BUILDLINK3_MK)
HEIMDAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.heimdal+=	heimdal>=0.4e
BUILDLINK_ABI_DEPENDS.heimdal+=	heimdal>=7.8.0nb6
BUILDLINK_PKGSRCDIR.heimdal?=	../../security/heimdal
BUILDLINK_INCDIRS.heimdal?=	include/krb5

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := heimdal
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.heimdal:Mldap}
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

CHECK_BUILTIN.heimdal:=	yes
.include "../../security/heimdal/builtin.mk"
CHECK_BUILTIN.heimdal:=	no
.if ${USE_BUILTIN.heimdal:tl} == no
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"
.endif # HEIMDAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-heimdal
