# $NetBSD: Makefile,v 1.1.1.1 2010/03/16 21:22:13 agc Exp $

DISTNAME=	itpp-4.0.7
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=itpp/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://sourceforge.net/apps/wordpress/itpp/
COMMENT=	Library of mathematical, signal processing and communication routines
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=	c c++ fortran

.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
