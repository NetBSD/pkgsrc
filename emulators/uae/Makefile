# $NetBSD: Makefile,v 1.19 2002/01/01 19:05:21 kristerw Exp $

DISTNAME=	uae-0.8.20
PKGNAME=	${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	http://www.freiburg.linux.de/~uae/bin/sources/develop/

MAINTAINER=	kristerw@netbsd.org
HOMEPAGE=	http://www.freiburg.linux.de/~uae/
COMMENT=	The UAE Amiga Emulator

DEPENDS=	unzip>=5.40:../../archivers/unzip

USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-dga --enable-vidmode --disable-ui

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} readdisk uae ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uae
	cd ${WRKSRC}/docs && ${INSTALL_DATA} FAQ README \
		${PREFIX}/share/doc/uae

.include "../../mk/bsd.pkg.mk"
