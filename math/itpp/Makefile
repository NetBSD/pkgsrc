# $NetBSD: Makefile,v 1.4 2012/09/13 13:23:33 asau Exp $

DISTNAME=	itpp-4.0.7
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=itpp/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/itpp/
COMMENT=	Library of mathematical, signal processing and communication routines
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake

USE_LANGUAGES+=	c c++ fortran77

.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
