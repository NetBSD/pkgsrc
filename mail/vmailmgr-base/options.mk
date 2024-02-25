# $NetBSD: options.mk,v 1.1 2024/02/25 12:09:21 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vmailmgr-base

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		cdb gdbm

PKG_SUPPORTED_OPTIONS=		kerberos # XXX or gssapi?
PKG_SUGGESTED_OPTIONS=		cdb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcdb)
# enabled by default
.endif

.if !empty(PKG_OPTIONS:Mgdbm)
CONFIGURE_ARGS+=		--with-vpwtable=gdbm
.include "../../databases/gdbm/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
CONFIGURE_ARGS+=		--with-krb5
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.endif
