# $NetBSD: Makefile,v 1.5 2003/12/04 19:48:24 xtraeme Exp $
#

DISTNAME=	buildtool-doc-0.14
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable build infrastructure - manual

BUILD_DEPENDS+=	docbook-xml>=4.2nb4:../../textproc/docbook-xml
BUILD_DEPENDS+=	docbook-xsl>=1.61.3:../../textproc/docbook-xsl

USE_BUILDLINK2=	yes

CONFIGURE_ENV+=	CATALOG_FILE="${XML_DEFAULT_CATALOG}"
CONFIGURE_ENV+=	DOCBOOK_XSL="${PREFIX}/share/xsl/docbook"

BUILDLINK_DEPMETHOD.libxml2?=	build
BUILDLINK_DEPMETHOD.libxslt?=	build
BUILDLINK_DEPMETHOD.xmlcatmgr?=	build

.include "../../devel/buildtool/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../textproc/xmlcatmgr/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
