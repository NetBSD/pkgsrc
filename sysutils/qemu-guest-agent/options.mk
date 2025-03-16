#	$NetBSD: options.mk,v 1.1 2025/03/16 20:07:39 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qemu-guest-agent
PKG_SUPPORTED_OPTIONS+=	doc
PKG_SUGGESTED_OPTIONS+=	doc

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mdoc}
PLIST.doc=		yes
CONFIGURE_ARGS+=	--enable-docs
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-rtd-theme>=1.2.0:../../textproc/py-sphinx-rtd-theme
.else
CONFIGURE_ARGS+=	--disable-docs
.endif
