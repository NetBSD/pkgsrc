# $NetBSD: options.mk,v 1.2 2024/06/10 06:16:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.json-c
PKG_SUPPORTED_OPTIONS=	doc

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
USE_TOOLS+=		pax:build
DEPENDS+=		doxygen>=1.8.13:../../devel/doxygen
BUILD_TARGET+=		doc
PLIST.doc=		yes
PRINT_PLIST_AWK+=	{ if (/^share\/doc/) $$0 = "$${PLIST.doc}" $$0 }

INSTALLATION_DIRS+=	share/doc/json-c

post-install:
	cd ${WRKSRC}/doc; ${PAX} -rw html ${DESTDIR}${PREFIX}/share/doc/json-c
.endif
