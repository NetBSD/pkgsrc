# $NetBSD: Makefile,v 1.47 2007/04/06 06:03:08 wiz Exp $

DISTNAME=	uae-0.8.25
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.coresystems.de/pub/uae/sources/develop/ \
		http://www.freiburg.linux.de/~uae/bin/sources/develop/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://uae.coresystems.de/
COMMENT=	The UAE Amiga Emulator

DEPENDS+=	unzip>=5.40:../../archivers/unzip

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-dga --enable-vidmode

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == NetBSD && exists(/usr/include/sys/statvfs.h)
CONFIGURE_ENV+=	cv_func_getmntinfo=yes fu_cv_sys_mounted_getmntinfo=yes
.endif

INSTALLATION_DIRS=	bin

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} readdisk uae ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uae
	cd ${WRKSRC}/docs && ${INSTALL_DATA} FAQ README \
		${PREFIX}/share/doc/uae

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
