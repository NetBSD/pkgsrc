# $NetBSD: Makefile,v 1.13 2020/06/02 08:24:01 adam Exp $

DISTNAME=	gimp-jxr-2.0
PKGREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	# javascript link
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chausner/gimp-jxr
COMMENT=	Gimp plugin for JPEG XR files
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/src

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	lib/gimp/2.0/plug-ins

CFLAGS+=	-I${BUILDLINK_PREFIX.jxrlib}/include/jxrlib/common/include
CFLAGS+=	-I${BUILDLINK_PREFIX.jxrlib}/include/jxrlib/image/sys
CFLAGS+=	-I${BUILDLINK_PREFIX.jxrlib}/include/jxrlib/image/encode
CFLAGS+=	-I${BUILDLINK_PREFIX.jxrlib}/include/jxrlib/image/decode
CFLAGS+=	-I${BUILDLINK_PREFIX.jxrlib}/include/jxrlib/image/x86
CFLAGS+=	-I${BUILDLINK_PREFIX.jxrlib}/include/jxrgluelib
CFLAGS+=	-D__ANSI__ -DABLE_PERF_MEASUREMENT
CFLAGS+=	load.c save.c utils.c
LDFLAGS+=	-L${BUILDLINK_PREFIX.jxrlib}/lib -ljxrglue -ljpegxr

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gimptool-2.0 --build file-jxr.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/file-jxr ${DESTDIR}${PREFIX}/lib/gimp/2.0/plug-ins

.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/jxrlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
