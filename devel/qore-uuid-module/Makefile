# $NetBSD: Makefile,v 1.17 2024/02/16 20:31:14 nros Exp $

DISTNAME=	qore-uuid-module-1.4.1
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	module-uuid
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.qore.org/
COMMENT=	UUID module for Qore
LICENSE=	gnu-lgpl-v2.1 OR mit

USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake
PTHREAD_OPTS+=	native

CMAKE_USE_GNU_INSTALL_DIRS=	no

#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/cmake/build.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
