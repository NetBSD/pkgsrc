# $NetBSD: Makefile,v 1.12 2006/04/11 14:47:06 jmmv Exp $
#

DISTNAME=	lib3ds-1.2.0
PKGREVISION=	5
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lib3ds/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://lib3ds.sourceforge.net/
COMMENT=	3D Studio File Format Library

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS=	autoconf automake

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

pre-configure:
	cd ${WRKSRC} && libtoolize --force
	cd ${WRKSRC} && autoreconf -i --force

.include "../../mk/bsd.pkg.mk"
