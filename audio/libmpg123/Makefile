# $NetBSD: Makefile,v 1.1.1.1 2008/09/07 00:56:15 bjs Exp $
#

.include "../../audio/libmpg123/Makefile.version"

DISTNAME=	mpg123-${MPG123_VERSION}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpg123/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://mpg123.sourceforge.net/
COMMENT=	MPEG layer 1, 2, and 3 decoder library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libmpg123.pc.in

BUILD_DIRS=		src/libmpg123
INSTALL_DIRS=		src/libmpg123

CONFIGURE_ARGS+=	--enable-fifo=yes
CONFIGURE_ARGS+=	--enable-modules=yes
CONFIGURE_ARGS+=	--enable-network=yes
CONFIGURE_ARGS+=	--enable-gapless=yes
###
### XXX Use pkgsrc-provided CFLAGS.
###
CONFIGURE_ARGS+=	--with-optimization=0
CFLAGS+=		${COPTS.mpg123:U${COPTS}}
###
### XXX This should be set to 'no' for platforms where it is required.
###	It's easier doing this here than patching configure.
MPG123_XFERMEM?=	yes
.if !empty(MPG123_XFERMEM:tl:Myes)
BUILDLINK_TRANSFORM+=	rm:-DNO_XFERMEM
.endif

LIBMPG123_PCDIR=	${PREFIX}/lib/pkgconfig
post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${LIBMPG123_PCDIR}
	${INSTALL_DATA} ${WRKSRC}/libmpg123.pc ${DESTDIR}${LIBMPG123_PCDIR}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
