# $NetBSD: Makefile,v 1.21 2024/05/29 16:31:48 adam Exp $

PKGNAME=	${DISTNAME:S/-/13-docs-/}
PKGREVISION=	1
COMMENT=	PostgreSQL database documentation

.include "../../databases/postgresql13/Makefile.common"

TOOL_DEPENDS+=	docbook-xml>=4.5:../../textproc/docbook-xml
TOOL_DEPENDS+=	docbook-xsl>=1.75.2:../../textproc/docbook-xsl
TOOL_DEPENDS+=	dsssl-docbook-modular>=1.79:../../textproc/dsssl-docbook-modular
TOOL_DEPENDS+=	iso8879>=1986:../../textproc/iso8879
TOOL_DEPENDS+=	openjade>=1.3.2:../../textproc/openjade
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_TOOLS+=		gzip tar perl:build
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share
CONFIGURE_ENV+=		DOCBOOKSTYLE="${PREFIX}/share/sgml/docbook/dsssl/modular"

BUILD_DIRS=	doc

.include "../../mk/bsd.pkg.mk"
