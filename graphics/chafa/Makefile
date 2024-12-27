# $NetBSD: Makefile,v 1.6 2024/12/27 08:19:52 wiz Exp $

DISTNAME=	chafa-1.14.5
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hpjansson/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/hpjansson/chafa/
COMMENT=	Command-line utility for displaying images in a terminal
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config autoconf automake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	chafa.pc.in

pre-configure:
	cd ${WRKSRC} && sh autogen.sh ${CONFIGURE_ARGS}

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
