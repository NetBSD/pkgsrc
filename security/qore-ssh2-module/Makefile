# $NetBSD: Makefile,v 1.20 2023/10/24 22:10:58 wiz Exp $

DISTNAME=	qore-ssh2-module-1.4.2
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	module-ssh2

MAINTAINER=	nros@NetBSD.org
COMMENT=	SSH2 module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1 OR mit

USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pax pkg-config
PTHREAD_OPTS+=	native

CMAKE_USE_GNU_INSTALL_DIRS=	no

#This is needed in order to comply the with MIT license and binary distribution
#Install docs
INSTALLATION_DIRS+=     share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
