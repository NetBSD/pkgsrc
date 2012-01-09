# $NetBSD: options.mk,v 1.1 2012/01/09 05:16:29 manu Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nss_ldap
PKG_SUPPORTED_OPTIONS=	krb5
PKG_SUGGESTED_OPTIONS=	krb5

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mkrb5)
SUBST_CLASSES+=		krb5
SUBST_STAGE.krb5=	post-configure
SUBST_FILES.krb5=	Makefile
SUBST_SED.krb5=		-e "s/-lkrb5//; s/-lcom_err//; s/-lgssapi//;"
.endif
