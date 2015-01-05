# $NetBSD: options.mk,v 1.1 2015/01/05 11:32:49 imil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pass

PKG_SUPPORTED_OPTIONS=	git xclip
PKG_SUGGESTED_OPTIONS=	git

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxclip)
DEPENDS+=	xclip>=0.12:../../x11/xclip
.endif

.if !empty(PKG_OPTIONS:Mgit)
.include "../../devel/git/Makefile.version"
DEPENDS+=	git-base>=${GIT_VERSION}:../../devel/git-base
.endif
