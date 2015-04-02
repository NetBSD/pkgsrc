# $NetBSD: Makefile,v 1.60 2015/04/02 23:03:00 tnn Exp $

DISTNAME=	glu-9.0.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/glu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgit.freedesktop.org/mesa/glu/
COMMENT=	GLU polygon tessellation facility for Mesa
LICENSE=	sgi-free-software-b-v2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	glu.pc.in

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
