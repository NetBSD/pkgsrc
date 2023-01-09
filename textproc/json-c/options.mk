# $NetBSD: options.mk,v 1.1 2023/01/09 18:16:14 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.json-c
PKG_SUPPORTED_OPTIONS=	doc
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
USE_TOOLS+=		pax:build
DEPENDS+=		doxygen>=1.8.13:../../devel/doxygen
BUILD_TARGET+=		doc
PLIST.doc=		yes

INSTALLATION_DIRS+=	share/doc/json-c

post-install:
	cd ${WRKSRC}/doc; ${PAX} -rw html ${DESTDIR}${PREFIX}/share/doc/json-c
.endif
