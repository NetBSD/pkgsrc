# $NetBSD: options.mk,v 1.3 2022/12/29 22:24:48 prlw1 Exp $

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
PQXXDOC=		${PREFIX}/share/doc/libpqxx
INSTALLATION_DIRS+=	share/doc/libpqxx
INSTALLATION_DIRS+=	share/examples/libpqxx

post-install:
	${INSTALL_DATA} ${PQXXDOCSRC}/*.html \
		${DESTDIR}${PQXXDOC}
	${INSTALL_DATA} ${PQXXDOCSRC}/doxygen.* \
		${DESTDIR}${PQXXDOC}
	${INSTALL_DATA} ${WRKSRC}/test/*.cxx \
		${DESTDIR}${PREFIX}/share/examples/libpqxx
.else
CONFIGURE_ARGS+=	--disable-documentation
.endif
