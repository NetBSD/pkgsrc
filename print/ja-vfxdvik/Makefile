# $NetBSD: Makefile,v 1.40 2014/02/12 23:18:29 tron Exp $

DISTNAME=	xdvik-${XDVIK_ORIGINAL_VERS}
PKGNAME=	ja-vfxdvik-${XDVIK_ORIGINAL_VERS}.${XDVIK_JP_PATCH_VERS}
PKGREVISION=	19
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

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex

.include "../../print/kpathsea/texmf.mk"

BUILD_DIRS=		texk/xdvik

USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	klibtool
GNU_CONFIGURE=		YES
LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm

CONFIGURE_ARGS+=--enable-local-texmf=${PREFIX}/share/texmf-dist \
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
		--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib \
		--with-zlib-include=${BUILDLINK_PREFIX.zlib}/include \
		--enable-xdviprint=${PREFIX}/bin/vfxdviprint \
		--enable-xdvietcdir=${PREFIX}/share/texmf-dist/vfxdvi

.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=--enable-a4
.endif

.if ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=--enable-auto-core
.else
USE_BUILTIN.zlib=	no # force use pkgsrc zlib
.endif

CONFIGURE_ENV+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q} \
		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q} \
		INSTALL_DATA=${INSTALL_DATA:Q}

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/ja-vflib-lib/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
