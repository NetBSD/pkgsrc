# $NetBSD: Makefile,v 1.9 2020/07/03 16:08:46 hauke Exp $

DISTNAME=	cmocka-1.1.5
CATEGORIES=	devel
MASTER_SITES=	https://cmocka.org/files/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cmocka.org/
COMMENT=	Unit testing framework for C supporting mock objects
LICENSE=	apache-2.0

USE_CMAKE=	yes

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

# GCC 4.3/4.4 provides wrong warnings:
# cmocka.c:3281: error: 'setup_name' may be used uninitialized in this function
CMAKE_ARGS+=	-DWITH_WERROR_UNINITIALIZED_FLAG=0

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"
