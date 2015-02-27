# $NetBSD: Makefile,v 1.1 2015/02/27 04:23:43 manu Exp $

DISTNAME=	cmocka-1.0.0
CATEGORIES=	devel
MASTER_SITES=	https://cmocka.org/files/1.0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cmocka.org/files/1.0/
COMMENT=	Unit testing framework for C supporing mock objects
LICENSE=	apache-2.0

FETCH_USING=	curl

USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKDIR}/${DISTNAME}

pre-configure:
		mkdir -p ${WRKSRC}
		rm -f ${WRKDIR}/${DISTNAME}/CMakeCache.txt

.include "../../mk/bsd.pkg.mk"
