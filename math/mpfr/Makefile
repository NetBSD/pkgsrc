# $NetBSD: Makefile,v 1.5 2005/12/05 23:55:12 rillig Exp $
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
CONFIGURE_ARGS+=	--with-gmp-include=${GMP_DIR:Q}
CONFIGURE_DIRS=		${GMP_DIR} ${WRKSRC}
BUILD_DIRS=		${WRKSRC}

INFO_FILES=		mpfr.info

GMP_VERSION?=		4.1.2
GMP=			gmp-${GMP_VERSION}
GMP_DIR=		${WRKDIR}/${GMP}

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
