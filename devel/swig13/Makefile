# $NetBSD: Makefile,v 1.3 2005/06/25 22:05:53 epg Exp $

DISTNAME=	swig-1.3.24
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator

CONFLICTS=      swig-build-[0-9]*

CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/1.3
BUILD_TARGET=		swig
WRKSRC=			${WRKDIR}/SWIG-1.3.24

USE_BUILDLINK3=		YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
