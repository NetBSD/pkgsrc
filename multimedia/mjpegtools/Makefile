# $NetBSD: Makefile,v 1.52 2012/07/07 15:49:00 adam Exp $

DISTNAME=	mjpegtools-2.0.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mjpeg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mjpeg.sourceforge.net/
COMMENT=	Programs for compressing video streams
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		mplex-[0-9]*
DEPENDS+=		toolame>=02l:../../audio/toolame
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash:run gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-libquicktime
CONFIGURE_ARGS+=	--enable-large-file
CONFIGURE_ARGS+=	--with-lame-includes=${BUILDLINK_PREFIX.lame}

SHLIBTOOL_OVERRIDE=	# empty
PKGCONFIG_OVERRIDE=	mjpegtools.pc.in
INFO_FILES=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-sdltest
CONFIGURE_ENV+=		mjt_cv_extern___progname=no
.else
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.endif

BUILDLINK_TRANSFORM+=	rm:-laudio

.include "options.mk"

.include "../../audio/lame/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
