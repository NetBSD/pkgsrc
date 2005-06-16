# $NetBSD: Makefile,v 1.37 2005/06/16 06:57:51 jlam Exp $

DISTNAME=	uae-0.8.22
PKGREVISION=	2
PKGNAME=	${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	http://www.freiburg.linux.de/~uae/bin/sources/develop/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.freiburg.linux.de/~uae/
COMMENT=	The UAE Amiga Emulator

DEPENDS=	unzip>=5.40:../../archivers/unzip

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-dga --enable-vidmode

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
.include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ui
.endif

.include "../../mk/compiler.mk"
.include "../../mk/x11.buildlink3.mk"

.if !empty(CC_VERSION:Mgcc-3.*)
post-configure:
	${TOUCH} ${WRKSRC}/src/tools/cpuopti.o
	${CP} ${CAT} ${WRKSRC}/src/tools/cpuopti
.endif

.if ${OPSYS} == NetBSD && exists(/usr/include/sys/statvfs.h)
CONFIGURE_ENV+=	cv_func_getmntinfo=yes fu_cv_sys_mounted_getmntinfo=yes
.endif

INSTALLATION_DIRS=	bin

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} readdisk uae ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uae
	cd ${WRKSRC}/docs && ${INSTALL_DATA} FAQ README \
		${PREFIX}/share/doc/uae

.include "../../mk/bsd.pkg.mk"
