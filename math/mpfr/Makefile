# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:30 tv Exp $
#

DISTNAME=		mpfr-2.0.3
PKGREVISION=	1
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/mpfr-current/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${GMP}${EXTRACT_SUFX}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.mpfr.org/
COMMENT=		GMP-based library for multiple-precision floating-point computations

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gmp-include=${GMP_DIR}
CONFIGURE_DIRS=		${GMP_DIR} ${WRKSRC}

INFO_FILES=		mpfr.info

GMP_VERSION?=		4.1.2
GMP=			gmp-${GMP_VERSION}
GMP_DIR=		${WRKDIR}/${GMP}

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
