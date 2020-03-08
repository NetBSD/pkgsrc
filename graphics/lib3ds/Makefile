# $NetBSD: Makefile,v 1.21 2020/03/08 16:47:48 wiz Exp $

DISTNAME=	lib3ds-1.2.0
PKGREVISION=	8
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lib3ds/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lib3ds.sourceforge.net/
COMMENT=	3D Studio File Format Library

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS=	autoconf automake

pre-configure:
	cd ${WRKSRC} && libtoolize --force
	cd ${WRKSRC} && autoreconf -i --force

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
