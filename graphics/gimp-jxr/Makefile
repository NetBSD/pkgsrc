# $NetBSD: Makefile,v 1.31 2024/05/29 16:32:52 adam Exp $

DISTNAME=	gimp-jxr-2.1.1
PKGREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=chausner/}
GITHUB_TAG=	version-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chausner/gimp-jxr
COMMENT=	Gimp plugin for JPEG XR files
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/gimp-jxr-version-${PKGVERSION_NOREV}/src

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
LDFLAGS+=	-lm	# for pow(3), needed by libjxrglue.a

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gimptool-2.0 --build file-jxr.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/file-jxr ${DESTDIR}${PREFIX}/lib/gimp/2.0/plug-ins

.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/jxrlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
