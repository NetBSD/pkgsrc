# $NetBSD: Makefile,v 1.21 2015/04/25 14:23:40 tnn Exp $

DISTNAME=		mpeg4ip-1.5.0.1
PKGREVISION=		2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mpeg4ip/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpeg4ip.sourceforge.net/
COMMENT=		Tools for streaming video and audio

CONFLICTS+=		faad2<2.0nb6

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config autoconf
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	bootstrap
OVERRIDE_DIRDEPTH=	3		# */*/*/libtool

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		mpeg4ipSDL
.if ${OPSYS} != "Darwin"
PLIST.mpeg4ipSDL=	yes
.endif

.if ${MACHINE_ARCH} == "i386"
PKG_OPTIONS_VAR=	PKG_OPTIONS.mpeg4ip
PKG_SUPPORTED_OPTIONS=	mmx
.include "../../mk/bsd.options.mk"

.  if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
BUILD_DEPENDS+=		nasm>=0.97.19:../../devel/nasm
.  else
CONFIGURE_ARGS+=	--disable-mmx
.  endif
.endif

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mgcc) || !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=		-fno-strict-aliasing
.endif

pre-configure:
	cd ${WRKSRC} && autoconf

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
