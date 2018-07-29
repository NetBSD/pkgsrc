# $NetBSD: Makefile,v 1.1 2018/07/29 07:38:48 wiz Exp $

DISTNAME=		djbsort-20180717
CATEGORIES=		math
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://sorting.cr.yp.to/
COMMENT=		Library for sorting arrays of integers
LICENSE=		public-domain

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON=		build test upgrade verif/tryinput

INSTALLATION_DIRS=	include lib

do-build:
	cd ${WRKSRC} && ./build

do-test: do-build
	cd ${WRKSRC} && ./test

do-install: do-test
	cd ${WRKSRC} && ./upgrade &&				\
	cd link-install/newest &&				\
	for i in include/*.h; do				\
	  ${INSTALL_DATA} $${i} ${DESTDIR}${PREFIX}/include;	\
	done;							\
	for i in lib/*/*.a; do					\
	  ${INSTALL_DATA} $${i} ${DESTDIR}${PREFIX}/lib;	\
	done

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
