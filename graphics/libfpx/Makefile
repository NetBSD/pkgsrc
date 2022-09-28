# $NetBSD: Makefile,v 1.6 2022/09/28 19:54:56 nros Exp $

libfpx_ver=	1.3.1
DISTNAME=	libfpx-${libfpx_ver}-10
PKGNAME=	libfpx-${libfpx_ver}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://imagemagick.org/archive/delegates/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	https://imagemagick.org/
COMMENT=	Library for reading and writing FlashPix images
LICENSE=	flashpix-license

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf

docdir=		 share/doc/${PKGBASE}
INSTALLATION_DIRS+=${docdir}

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	${INSTALL_DATA} ${WRKSRC}/flashpix.h \
		${DESTDIR}${PREFIX}/${docdir}/copyright-notice
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/${docdir}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS \
		${DESTDIR}${PREFIX}/${docdir}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog \
		${DESTDIR}${PREFIX}/${docdir}
	${INSTALL_DATA} ${WRKSRC}/doc/readme.txt \
		${DESTDIR}${PREFIX}/${docdir}

.include "../../mk/bsd.pkg.mk"
