# $NetBSD: options.mk,v 1.2 2018/05/06 11:56:58 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pass

PKG_SUPPORTED_OPTIONS=		git x11
PKG_SUGGESTED_OPTIONS=		git
PKG_OPTIONS_LEGACY_OPTS+=	xclip:x11

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
