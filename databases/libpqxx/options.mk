# $NetBSD: options.mk,v 1.2 2021/01/07 16:29:30 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libpqxx
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc
.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-documentation
PLIST.doc=		yes
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
TOOL_DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz

PQXXDOCSRC=		${WRKSRC}/doc/html
PQXXDOC=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${PQXXDOC}/Reference
INSTALLATION_DIRS+=	share/examples/libpqxx

post-install:
	${INSTALL_DATA} ${PQXXDOCSRC}/Reference/*.html \
		${DESTDIR}${PQXXDOC}/Reference
	${INSTALL_DATA} ${PQXXDOCSRC}/Reference/doxygen.* \
		${DESTDIR}${PQXXDOC}/Reference
	${INSTALL_DATA} ${WRKSRC}/test/*.cxx \
		${DESTDIR}${PREFIX}/share/examples/libpqxx
.else
CONFIGURE_ARGS+=	--disable-documentation
.endif
