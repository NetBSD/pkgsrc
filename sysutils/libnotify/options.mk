# $NetBSD: options.mk,v 1.5 2019/08/16 10:09:37 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnotify
PKG_SUPPORTED_OPTIONS=	doc
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
PLIST.doc=		yes
.endif
