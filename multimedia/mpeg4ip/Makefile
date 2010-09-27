# $NetBSD: Makefile,v 1.17 2010/09/27 09:09:28 obache Exp $

DISTNAME=		mpeg4ip-1.5.0.1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mpeg4ip/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpeg4ip.sourceforge.net/
COMMENT=		Tools for streaming video and audio

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		faad2<2.0nb6

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
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

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
