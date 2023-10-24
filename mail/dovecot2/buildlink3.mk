# $NetBSD: buildlink3.mk,v 1.40 2023/10/24 22:09:42 wiz Exp $

BUILDLINK_TREE+=	dovecot

.if !defined(DOVECOT_BUILDLINK3_MK)
DOVECOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dovecot+=		dovecot>=2.2.0
# must match current package version for plugins to load
BUILDLINK_ABI_DEPENDS.dovecot+=		dovecot>=2.3.21nb1
BUILDLINK_PKGSRCDIR.dovecot?=		../../mail/dovecot2

pkgbase:=	dovecot
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.dovecot:Mssl}
.  include "../../security/openssl/buildlink3.mk"
.endif
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # DOVECOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dovecot
