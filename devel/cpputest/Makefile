# $NetBSD: Makefile,v 1.1 2016/05/06 18:08:45 schmonz Exp $

GITHUB_PROJECT=		cpputest
DISTNAME=		v3.7.1
PKGNAME=		${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=cpputest/}
EXTRACT_SUFX=		.zip
DIST_SUBDIR=		${GITHUB_PROJECT}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		${MASTER_SITE_GITHUB:=cpputest/cpputest/}
COMMENT=		Unit testing and mocking framework for C/C++
LICENSE=		modified-bsd

WRKSRC=			${WRKDIR}/cpputest-3.7.1

PKGCONFIG_OVERRIDE+=	cpputest.pc.in

#USE_CMAKE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_DIRS=		cpputest_build
BUILD_DIRS=		${CONFIGURE_DIRS}
USE_TOOLS+=		automake autoreconf pkg-config
USE_LANGUAGES=		c c++

pre-configure:
	cd ${WRKSRC}/${CONFIGURE_DIRS} && autoreconf .. -fiv

# $ ../configure
# $ make

.include "../../mk/bsd.pkg.mk"
