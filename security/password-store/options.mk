# $NetBSD: options.mk,v 1.3 2018/06/14 16:08:39 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.password-store

PKG_SUPPORTED_OPTIONS=		git x11
PKG_SUGGESTED_OPTIONS=		git
PKG_OPTIONS_LEGACY_OPTS+=	xclip:x11

.include "../../mk/bsd.prefs.mk"

.if defined(PKG_OPTIONS.pass)
PKG_LEGACY_OPTIONS+=		${PKG_OPTIONS.pass}
PKG_OPTIONS_DEPRECATED_WARNINGS+= \
	"Deprecated variable PKG_OPTIONS.pass used, use ${PKG_OPTIONS_VAR} instead."
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=	base64-[0-9]*:../../converters/base64
DEPENDS+=	qrencode-[0-9]*:../../converters/qrencode
DEPENDS+=	xclip>=0.12:../../x11/xclip
.endif

.if !empty(PKG_OPTIONS:Mgit)
.include "../../devel/git/Makefile.version"
DEPENDS+=	git-base>=${GIT_VERSION}:../../devel/git-base
.endif
