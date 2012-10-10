# $NetBSD: options.mk,v 1.2 2012/10/10 19:49:07 markd Exp $
#

PKG_OPTIONS_VAR=        PKG_OPTIONS.alpine
PKG_SUPPORTED_OPTIONS=  ldap kerberos pinepwd
PKG_SUGGESTED_OPTIONS=  pinepwd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
CONFIGURE_ARGS+=	--with-krb5
.include "../../mk/krb5.buildlink3.mk"
MAKE_ENV+=	KRB5_TYPE=${KRB5_TYPE}
MAKE_FLAGS+=	EXTRAAUTHENTICATORS=gss
EXTRASPECIALS+=	GSSDIR=${KRB5BASE}
CFLAGS.heimdal=	-DHEIMDAL_KRB5
CFLAGS+=	${CFLAGS.${KRB5_TYPE}}
MAKE_FLAGS+=	EXTRALDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	EXTRACFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	EXTRASPECIALS=${EXTRASPECIALS:Q}
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=        --with-ldap
.include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpinepwd)
CONFIGURE_ARGS+= --with-passfile=.pinepwd
.endif
