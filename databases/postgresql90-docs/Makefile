# $NetBSD: Makefile,v 1.1.1.1 2010/09/21 07:52:02 adam Exp $

PKGNAME=	postgresql90-docs-${BASE_VERS}
COMMENT=	PostgreSQL database documentation

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql90/Makefile.common"

BUILD_DEPENDS+=	docbook-xml>=4.5:../../textproc/docbook-xml
BUILD_DEPENDS+=	docbook-xsl>=1.75.2:../../textproc/docbook-xsl
BUILD_DEPENDS+=	dsssl-docbook-modular>=1.79:../../textproc/dsssl-docbook-modular
BUILD_DEPENDS+=	iso8879>=1986:../../textproc/iso8879
BUILD_DEPENDS+=	openjade>=1.3.2:../../textproc/openjade

USE_TOOLS+=		gzip tar perl:build
CONFIGURE_ENV+=		DOCBOOKSTYLE="${PREFIX}/share/sgml/docbook/dsssl/modular"
INSTALL_DIRS+=	doc

BUILD_DIRS=	${INSTALL_DIRS}

post-install:
	set -e; cd ${WRKSRC}/doc; for file in				\
		FAQ* KNOWN_BUGS MISSING_FEATURES README.* TODO		\
		bug.template;						\
	do								\
		${INSTALL_DATA} $$file ${DESTDIR}${PG_DOC_DIR}/$$file;	\
	done

.include "../../mk/bsd.pkg.mk"
