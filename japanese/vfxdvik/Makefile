# $NetBSD: Makefile,v 1.3 2001/10/30 22:46:27 kei Exp $
#

DISTNAME=	xdvik-22.15
PKGNAME=	ja-vfxdvik-22.15
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.appi.keio.ac.jp/pub/xdvi/

PATCH_SITES=	ftp://ftp.appi.keio.ac.jp/pub/xdvi/
PATCHFILES=	xdvik-22.15-j1.04.patch.gz
PATCH_DIST_ARGS=-d ${WRKSRC} --quiet -E -p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	# no home page
COMMENT=	xdvik with vflib

DEPENDS+=	TeXfamily>=1.2.1:../../japanese/texfamily
DEPENDS+=	ja-vflib-lib>=[0-9]*:../../japanese/vflib-lib

XDVI_DIR=	${WRKDIR}/${DISTNAME}/texk/xdvik

USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-local-texmf=texmf.local \
		--without-texinfo \
		--without-dialog \
		--disable-multiplatform \
		--enable-ipc \
		--with-epsfwin \
		--with-hp2627win \
		--with-mftalkwin \
		--with-x11 \
		--with-system-wwwlib=yes \
		--with-libwww-config=${LOCALBASE}/bin/libwww-config \
		--with-system-pnglib \
		--with-pnglib-libdir=${LOCALBASE}/lib \
		--with-pnglib-include=${LOCALBASE}/include \
		--with-system-zlib \
		--enable-xdviprint=${LOCALBASE}/bin/vfxdviprint \
		--enable-xdvietcdir=${LOCALBASE}/share/texmf.local/vfxdvi

.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=--enable-a4
.endif

.if ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=--enable-auto-core \
		--with-zlib-libdir=/usr/lib \
		--with-zlib-include=/usr/include
.else
CONFIGURE_ARGS+= --with-zlib-libdir=${LOCALBASE}/lib \
		--with-zlib-include=${LOCALBASE}/include
.endif

CONFIGURE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

do-build:
	cd ${XDVI_DIR} && ${MAKE_PROGRAM}

do-install:
	cd ${XDVI_DIR} && ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"
