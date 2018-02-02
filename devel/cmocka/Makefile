# $NetBSD: Makefile,v 1.5 2018/02/02 10:31:07 jperkin Exp $

DISTNAME=	cmocka-1.0.1
CATEGORIES=	devel
MASTER_SITES=	https://cmocka.org/files/1.0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cmocka.org/files/1.0/
COMMENT=	Unit testing framework for C supporing mock objects
LICENSE=	apache-2.0

USE_CMAKE=	yes

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"
