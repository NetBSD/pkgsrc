# $NetBSD: Makefile,v 1.12 2022/01/27 18:20:27 nros Exp $

DISTNAME=	qore-ssh2-module-1.4.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	module-ssh2

MAINTAINER=	nros@NetBSD.org
COMMENT=	SSH2 module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pax
PTHREAD_OPTS+=	native

CONFIGURE_ARGS+=	--with-libsuffix=""

#This is needed in order to comply the with MIT license and binary distribution
#Install docs
INSTALLATION_DIRS+=     share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC}/docs/ssh2 && ${PAX} -wr * \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
