# $NetBSD: Makefile,v 1.38 2004/10/03 00:14:50 tv Exp $

DISTNAME=	freetype-2.1.9
PKGNAME=	freetype2-2.1.9
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/} \
		ftp://ftp.freetype.org/freetype/freetype2/ \
		ftp://ftp.ntua.gr/mirror/freetype/freetype2/ \
		ftp://ring.aist.go.jp/pub/graphics/freetype/freetype2/ \
		ftp://sunsite.cnlab-switch.ch/mirror/freetype/freetype2/ \
		http://gd.tuwien.ac.at/publishing/freetype/freetype2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.freetype.org/
COMMENT=	Font rendering engine and library API

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		grep make
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		${WRKSRC}/builds/unix
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include

PKGCONFIG_OVERRIDE=	builds/unix/freetype2.in

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if defined(MKTTINTERP) && !empty(MKTTINTERP:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	truetype
.endif
PKG_OPTIONS_VAR+=	PKG_OPTIONS.freetype2
PKG_SUPPORTED_OPTIONS=	truetype
.include "../../mk/bsd.options.mk"

###
### This builds freetype2 with the TrueType bytecode interpreter.  Note
### that there are important patent issues related to the use of the
### interpreter:
###
###	http://www.freetype.org/patents.html
###
.if !empty(PKG_OPTIONS:Mtruetype)
CFLAGS+=	-DTT_CONFIG_OPTION_BYTECODE_INTERPRETER
.endif

# reduce optimization level on alpha to avoid compiler bugs
.if !empty(MACHINE_PLATFORM:MNetBSD-*-alpha)
CPPFLAGS:=	${CPPFLAGS:C/-O[0-9]*/-O/g}
CFLAGS:=	${CFLAGS:C/-O[0-9]*/-O/g}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"
.endif

# source code breaks strict aliasing in gcc>=2.95
.if !empty(CC_VERSION:Mgcc-[3-9]*) || !empty(CC_VERSION:Mgcc-2.95*)
CFLAGS+=	-fno-strict-aliasing
.endif

.include "../../devel/zlib/buildlink3.mk"

post-configure:
	cd ${WRKSRC} && ${LN} -s builds/unix/unix.mk config.mk
.if ${OPSYS} == "IRIX"
	${MKDIR} ${WRKSRC}/.libs
.endif

.include "../../mk/bsd.pkg.mk"
