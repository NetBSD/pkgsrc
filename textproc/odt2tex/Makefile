# $NetBSD: Makefile,v 1.21 2023/11/08 13:21:07 wiz Exp $

DISTNAME=	odt2tex-0.0.13
PKGREVISION=	15
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=simonaw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.chronowerks.de/odt/
COMMENT=	Convert ODT (Libre/OpenOffice text documents) to LaTeX input files
LICENSE=	mit

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,-O2
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-O2

.include "../../archivers/libzip/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
