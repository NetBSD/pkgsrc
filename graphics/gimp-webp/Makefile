# $NetBSD: Makefile,v 1.13 2019/07/21 22:24:59 wiz Exp $

DISTNAME=	gimp-webp-0.2
PKGREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nathan-osman/}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nathan-osman/gimp-webp
COMMENT=	WebP Gimp I/O plugin
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
