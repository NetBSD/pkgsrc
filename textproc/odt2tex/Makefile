# $NetBSD: Makefile,v 1.6 2017/09/03 08:37:00 wiz Exp $

DISTNAME=	odt2tex-0.0.13
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=simonaw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.chronowerks.de/odt/
COMMENT=	Convert ODT (Libre/OpenOffice text documents) to LaTeX input files
LICENSE=	mit

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config

.include "../../archivers/libzip/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
