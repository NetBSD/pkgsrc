# $NetBSD: Makefile,v 1.12 2023/10/24 22:09:25 wiz Exp $

DISTNAME=	jp2a-1.0.7
PKGREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=cslarsen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	https://github.com/cslarsen/jp2a
COMMENT=	JPEG to ASCII converter
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	automake autoconf autoreconf
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -vi

.include "options.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
