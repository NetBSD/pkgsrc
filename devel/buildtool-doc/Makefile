# $NetBSD: Makefile,v 1.12 2004/10/03 00:13:25 tv Exp $
#

DISTNAME=	buildtool-doc-0.16
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable build infrastructure - manual

BUILD_DEPENDS+=	docbook-xml>=4.2nb4:../../textproc/docbook-xml
BUILD_DEPENDS+=	docbook-xsl>=1.61.3:../../textproc/docbook-xsl

USE_BUILDLINK3=	yes

CONFIGURE_ARGS+=	--dir-html=${PREFIX}/share/doc/buildtool-doc/html
CONFIGURE_ENV+=	CATALOG_FILE="${XML_DEFAULT_CATALOG}"
CONFIGURE_ENV+=	DOCBOOK_XSL="${PREFIX}/share/xsl/docbook"

BUILDLINK_DEPMETHOD.libxml2?=	build
BUILDLINK_DEPMETHOD.libxslt?=	build
BUILDLINK_DEPMETHOD.xmlcatmgr?=	build

.include "../../devel/buildtool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
