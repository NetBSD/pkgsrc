# $NetBSD: Makefile,v 1.40 2006/01/24 07:32:06 wiz Exp $

DISTNAME=	uae-0.8.25
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.freiburg.linux.de/~uae/bin/sources/develop/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.freiburg.linux.de/~uae/
COMMENT=	The UAE Amiga Emulator

DEPENDS+=	unzip>=5.40:../../archivers/unzip

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-dga --enable-vidmode

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ui
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

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
