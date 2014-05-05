# $NetBSD: Makefile,v 1.72 2014/05/05 00:47:50 ryoon Exp $

DISTNAME=	uae-0.8.25
PKGREVISION=	23
CATEGORIES=	emulators
MASTER_SITES=	http://www.freiburg.linux.de/~uae/bin/sources/develop/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://uae.coresystems.de/
COMMENT=	The UAE Amiga Emulator

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake pkg-config unzip:run
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-dga --enable-vidmode

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == NetBSD && exists(/usr/include/sys/statvfs.h)
CONFIGURE_ENV+=	cv_func_getmntinfo=yes fu_cv_sys_mounted_getmntinfo=yes
.endif

INSTALLATION_DIRS=	bin

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} readdisk uae ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/uae
	cd ${WRKSRC}/docs && ${INSTALL_DATA} FAQ README \
		${DESTDIR}${PREFIX}/share/doc/uae

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
