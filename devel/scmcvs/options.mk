# $NetBSD: options.mk,v 1.2 2008/01/04 06:48:06 martti Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cvs
PKG_SUPPORTED_OPTIONS=	kerberos

.include "../../mk/bsd.prefs.mk"

.if empty(MACHINE_PLATFORM:MSunOS-5.[89]-*) && \
    empty(MACHINE_PLATFORM:MSunOS-5.10-*) && \
    empty(MACHINE_PLATFORM:MLinux-*) && \
    defined(NOT_YET_AVAILABLE_FOR_CVS_1_11_21)
PKG_SUPPORTED_OPTIONS+=	inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		cvs-1.11.19-v6-20050205.diff.gz
PATCH_DIST_STRIP=	-p1
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-encryption
CONFIGURE_ARGS+=	--with-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-krb4=${KRB5BASE}
.  if ${OPSYS} == "Darwin"
LDFLAGS+=		-framework Kerberos
.  endif
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif
