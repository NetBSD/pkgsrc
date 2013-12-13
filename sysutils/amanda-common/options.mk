# $NetBSD: options.mk,v 1.10 2013/12/13 12:42:12 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.amanda
# Common options.
PKG_SUPPORTED_OPTIONS+=	inet6 amanda-fqdn amanda-ssh kerberos
PKG_SUGGESTED_OPTIONS+=	inet6 amanda-fqdn amanda-ssh kerberos
# Client options.
PKG_SUPPORTED_OPTIONS+=	amanda-smb amanda-dump-snap
PKG_SUGGESTED_OPTIONS+=	amanda-dump-snap

PKG_OPTIONS_LEGACY_VARS+=	AMANDA_FQDN:amanda-fqdn
PKG_OPTIONS_LEGACY_VARS+=	AMANDA_SSH:amanda-ssh
PKG_OPTIONS_LEGACY_VARS+=	AMANDA_SMB:amanda-smb
PKG_OPTIONS_LEGACY_VARS+=	AMANDA_DUMP_SNAP:amanda-dump-snap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if !empty(PKG_OPTIONS:Mamanda-fqdn)
CONFIGURE_ARGS+=        --with-fqdn
.endif

.if !empty(PKG_OPTIONS:Mamanda-ssh)
CONFIGURE_ARGS+=        --with-ssh-security

.  if !exists(/usr/bin/ssh)
DEPENDS+=		openssh-[0-9]*:../../security/openssh
FIND_PREFIX:= 		SSHPREFIX=openssh
.include "../../mk/find-prefix.mk"
CONFIGURE_ENV+=		ac_cv_path_SSH=${SSHPREFIX}/bin/ssh
.  endif
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.  if ${OPSYS} == "SunOS"
USE_BUILTIN.mit-krb5=	no
.  endif
CONFIGURE_ARGS+=	--with-krb5-security=${KRB5BASE:Q}
.  include "../../mk/krb5.buildlink3.mk"
.endif
