# $NetBSD: Makefile,v 1.16 2001/08/01 20:44:03 kristerw Exp $

DISTNAME=	uae-0.8.17
PKGNAME=	${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freiburg.linux.de/pub/uae/sources/develop/

MAINTAINER=	kristerw@netbsd.org
HOMEPAGE=	http://www.freiburg.linux.de/~uae/
COMMENT=	The UAE Amiga Emulator

DEPENDS=	unzip>=5.40:../../archivers/unzip

USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

# Because using the gtk+ user interface requires a thread library
# we use a brute force method to avoid detection of gtk+.
CONFIGURE_ARGS+=	--enable-dga --enable-vidmode \
			--with-gtk-prefix=${WRKDIR}

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} readdisk uae ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uae
	cd ${WRKSRC}/docs && ${INSTALL_DATA} FAQ README \
		${PREFIX}/share/doc/uae

.include "../../mk/bsd.pkg.mk"
