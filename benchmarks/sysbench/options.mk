# $NetBSD: options.mk,v 1.2 2007/03/06 21:53:56 rmind Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sysbench
PKG_SUPPORTED_OPTIONS+= mysql pgsql doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client:Q}
.  include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX:Q}
.  include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if !empty(PKG_OPTIONS:Mdoc)
PLIST_SUBST+=	DOC=
.  include "../../textproc/libxslt/buildlink3.mk"
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
.else
PLIST_SUBST+=	DOC="@comment "
.endif

do-install:
.if !empty(PKG_OPTIONS:Mdoc)
	${PREFIX}/bin/xsltproc -o ${WRKSRC}/doc/manual.html \
		${PREFIX}/share/xsl/docbook/xhtml/docbook.xsl \
		${WRKSRC}/doc/manual.xml
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sysbench
	${INSTALL_DATA} ${WRKSRC}/doc/manual.xml \
		${PREFIX}/share/doc/sysbench
.endif
