# $NetBSD: Makefile,v 1.39 2002/11/30 11:46:07 salo Exp $
#

DISTNAME=	xmms-1.2.7
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.xmms.org/xmms/1.2.x/ \
		ftp://ftp.sunet.se/pub/multimedia/xmms/1.2.x/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.xmms.org/
COMMENT=	X Multimedia System --- An audio player with a Winamp GUI

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-gnome
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# Broken configure script assumes that iconv_open lives in libc; work around.  
CPPFLAGS+=		-DHAVE_ICONV_OPEN=1
CONFIGURE_ENV+=		ac_cv_func_iconv_open=yes
LIBS+=			-liconv

.include "../../mk/bsd.prefs.mk"

PTHREAD_OPTS+=		require

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if (${OPSYS} == NetBSD)
CONFIGURE_ARGS+=	--with-dev-dsp=${DEVOSSSOUND}
CPPFLAGS+=		-DHAVE_NANOSLEEP=1

.  if (${MACHINE_ARCH} == i386)
post-patch:
.    if (${OBJECT_FMT} == a.out)
	${CP} ${FILESDIR}/decode_i586_.s ${WRKSRC}/Input/mpg123/decode_i586.s
.    endif
	cd ${WRKSRC}/Input/mpg123 && \
	${MV} decode_i586.s decode_i586.s.orig && \
	${SED} -e 's@^/@#/@g' <decode_i586.s.orig >decode_i586.s
.  endif
.endif

.include "../../audio/esound/buildlink2.mk"
.include "../../audio/libmikmod/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
