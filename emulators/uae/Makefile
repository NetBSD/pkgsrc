# $NetBSD: Makefile,v 1.25 2003/09/23 19:05:05 tron Exp $

DISTNAME=	uae-0.8.22
PKGNAME=	${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	http://www.freiburg.linux.de/~uae/bin/sources/develop/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.freiburg.linux.de/~uae/
COMMENT=	The UAE Amiga Emulator

DEPENDS=	unzip>=5.40:../../archivers/unzip

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-dga --enable-vidmode --disable-ui

.include "../../mk/bsd.prefs.mk"

post-configure:
.if ${OPSYS} == NetBSD && defined(HAVE_GCC3) && ${HAVE_GCC3} == yes
	${TOUCH} ${WRKSRC}/src/tools/cpuopti.o
	${CP} ${CAT} ${WRKSRC}/src/tools/cpuopti
.endif

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} readdisk uae ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uae
	cd ${WRKSRC}/docs && ${INSTALL_DATA} FAQ README \
		${PREFIX}/share/doc/uae

.include "../../mk/bsd.pkg.mk"
