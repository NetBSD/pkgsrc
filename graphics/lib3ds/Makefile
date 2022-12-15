# $NetBSD: Makefile,v 1.25 2022/12/15 10:37:02 jperkin Exp $

DISTNAME=	lib3ds-1.2.0
PKGREVISION=	10
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lib3ds/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lib3ds.sourceforge.net/
COMMENT=	3D Studio File Format Library

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS=	autoconf automake

pre-configure:
	cd ${WRKSRC} && libtoolize --force
	cd ${WRKSRC} && autoreconf -i --force

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
