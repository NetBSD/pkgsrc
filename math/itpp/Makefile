# $NetBSD: Makefile,v 1.6 2020/10/12 21:52:02 bacon Exp $

DISTNAME=	itpp-4.0.7
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=itpp/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/itpp/
COMMENT=	Library of mathematical, signal processing and communication routines
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake

USE_LANGUAGES+=	c c++ fortran77

.include "../../mk/blas.buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
