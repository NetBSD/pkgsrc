# $NetBSD: Makefile,v 1.31 2004/06/01 18:25:57 tron Exp $

DISTNAME=	uae-0.8.22
PKGNAME=	${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	http://www.freiburg.linux.de/~uae/bin/sources/develop/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.freiburg.linux.de/~uae/
COMMENT=	The UAE Amiga Emulator

DEPENDS=	unzip>=5.40:../../archivers/unzip

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-dga --enable-vidmode --disable-ui

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-3.*)
post-configure:
	${TOUCH} ${WRKSRC}/src/tools/cpuopti.o
	${CP} ${CAT} ${WRKSRC}/src/tools/cpuopti
.endif

.if ${OPSYS} == NetBSD && exists(/usr/include/sys/statvfs.h)
CONFIGURE_ENV+=	cv_func_getmntinfo=yes fu_cv_sys_mounted_getmntinfo=yes
.endif

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} readdisk uae ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uae
	cd ${WRKSRC}/docs && ${INSTALL_DATA} FAQ README \
		${PREFIX}/share/doc/uae

.include "../../mk/bsd.pkg.mk"
