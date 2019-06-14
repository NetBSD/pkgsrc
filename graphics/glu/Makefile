# $NetBSD: Makefile,v 1.65 2019/06/14 10:22:46 jperkin Exp $

DISTNAME=	glu-9.0.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/glu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/mesa/glu/
COMMENT=	GLU polygon tessellation facility for Mesa
LICENSE=	sgi-free-software-b-v2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	glu.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
