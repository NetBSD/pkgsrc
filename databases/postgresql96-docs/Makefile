# $NetBSD: Makefile,v 1.3 2018/11/09 18:12:27 adam Exp $

PKGNAME=	${DISTNAME:C/-/96-docs-/}
COMMENT=	PostgreSQL database documentation

.include "../../databases/postgresql96/Makefile.common"

BUILD_DEPENDS+=	docbook-xml>=4.5:../../textproc/docbook-xml
BUILD_DEPENDS+=	docbook-xsl>=1.75.2:../../textproc/docbook-xsl
BUILD_DEPENDS+=	dsssl-docbook-modular>=1.79:../../textproc/dsssl-docbook-modular
BUILD_DEPENDS+=	iso8879>=1986:../../textproc/iso8879
BUILD_DEPENDS+=	openjade>=1.3.2:../../textproc/openjade
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_TOOLS+=		gzip tar perl:build
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share
CONFIGURE_ENV+=		DOCBOOKSTYLE="${PREFIX}/share/sgml/docbook/dsssl/modular"

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
