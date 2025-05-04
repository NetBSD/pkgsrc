# $NetBSD: options.mk,v 1.1 2025/05/04 13:17:38 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dropbear
PKG_SUPPORTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
SUBST_CLASSES+=		pam
SUBST_MESSAGE.pam=	Enabling PAM in options.h
SUBST_STAGE.pam=	pre-configure
SUBST_FILES.pam=	options.h
SUBST_SED.pam=		-e "s/ENABLE_SVR_PASSWORD_AUTH/ENABLE_SVR_PAM_AUTH/"
.endif
