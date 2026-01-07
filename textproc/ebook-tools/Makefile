# $NetBSD: Makefile,v 1.42 2026/01/07 08:49:02 wiz Exp $

# also update lit2epub if you update this package.
DISTNAME=	ebook-tools-0.2.2
PKGREVISION=	27
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ebook-tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ebook-tools.sourceforge.net/
COMMENT=	Tools for accessing and converting various ebook file formats
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
