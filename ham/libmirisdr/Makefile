# $NetBSD: Makefile,v 1.2 2015/01/26 06:56:43 dbj Exp $

PKGNAME=	libmirisdr-0.1
DISTNAME=	libmirisdr-${VERSION}
VERSION=	59ba372
CATEGORIES=	ham
MASTER_SITES=	-http://cgit.osmocom.org/libmirisdr/snapshot/libmirisdr-${VERSION}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgit.osmocom.org/libmirisdr/
COMMENT=	Osmocom Mirics MSi2500 + MSi001 SDR library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	cmake pkg-config
USE_CMAKE=	yes

# Suppress warning for developer
CMAKE_ARGS+=	-Wno-dev

.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
