# $NetBSD: Makefile,v 1.11 2004/04/26 01:30:42 snj Exp $

DISTNAME=	xdvik-${XDVIK_ORIGINAL_VERS}
PKGNAME=	ja-vfxdvik-${XDVIK_ORIGINAL_VERS}.${XDVIK_JP_PATCH_VERS}
PKGREVISION=	4
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xdvi/} # not xdvik

PATCH_SITES=	http://www.nn.iij4u.or.jp/~tutimura/tex/
PATCHFILES=	${DISTNAME}-${XDVIK_JP_PATCH_VERS}.patch.gz
PATCH_DIST_ARGS=-d ${WRKSRC} --quiet -E -p1

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.nn.iij4u.or.jp/~tutimura/tex/xdvi.html
COMMENT=	Xdvik with vflib

XDVIK_ORIGINAL_VERS=	22.40v
XDVIK_JP_PATCH_VERS=	j1.14

.if defined(USE_TEXFAMILY)
DEPENDS+=	TeXfamily>=1.2.1:../../print/texfamily
.else
DEPENDS+=	ja-ptex-bin>=3.1.2:../../print/ja-ptex-bin
.endif

XDVI_DIR=	${WRKDIR}/${DISTNAME}/texk/xdvik

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/config/config
LIBTOOL_OVERRIDE=	klibtool
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=--enable-local-texmf=${PREFIX}/share/texmf.local \
		--without-texinfo \
		--without-dialog \
		--disable-multiplatform \
		--enable-ipc \
		--with-epsfwin \
		--with-hp2627win \
		--with-mftalkwin \
		--with-x11 \
		--with-system-wwwlib \
		--with-system-pnglib \
		--with-system-t1lib \
		--with-system-zlib \
		--enable-xdviprint=${PREFIX}/bin/vfxdviprint \
		--enable-xdvietcdir=${PREFIX}/share/texmf.local/vfxdvi

.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=--enable-a4
.endif

.if ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=--enable-auto-core \
		--with-zlib-libdir=/usr/lib \
		--with-zlib-include=/usr/include
.else
CONFIGURE_ARGS+= --with-zlib-libdir=${PREFIX}/lib \
		--with-zlib-include=${PREFIX}/include
.endif

CONFIGURE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

do-build:
	cd ${XDVI_DIR} && ${MAKE_PROGRAM}

do-install:
	cd ${XDVI_DIR} && ${MAKE_PROGRAM} install

.if defined(USE_TEXFAMILY)
.include "../../print/teTeX1-bin/kpathsea.buildlink3.mk"
.else
.include "../../print/teTeX-bin/kpathsea.buildlink3.mk"
.endif
.include "../../www/libwww/buildlink3.mk"
.include "../../print/ja-vflib-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
