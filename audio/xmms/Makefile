# $NetBSD: Makefile,v 1.28 2002/06/25 08:17:33 abs Exp $
# FreeBSD: ports/audio/xmms/Makefile,v 1.9 2000/02/11 01:46:12 cpiazza Exp

DISTNAME=	xmms-1.2.7
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.xmms.org/xmms/1.2.x/ \
		ftp://ftp.sunet.se/pub/multimedia/xmms/1.2.x/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.xmms.org/
COMMENT=	X Multimedia System --- An audio player with a Winamp GUI

USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-gnome
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
CONFIGURE_ARGS+=	--with-dev-dsp=/dev/sound
CPPFLAGS+=		-DHAVE_NANOSLEEP=1

.if (${MACHINE_ARCH} == i386)
post-patch:
.if (${OBJECT_FMT} == a.out)
	${CP} ${FILESDIR}/decode_i586_.s ${WRKSRC}/Input/mpg123/decode_i586.s
.endif
	cd ${WRKSRC}/Input/mpg123 && \
	${MV} decode_i586.s decode_i586.s.orig && \
	${SED} -e 's@^/@#/@g' <decode_i586.s.orig >decode_i586.s
.endif
.endif

.include "../../audio/esound/buildlink.mk"
.include "../../audio/libmikmod/buildlink.mk"
.include "../../audio/libvorbis/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"

.if (${PTHREAD_TYPE} == pth)	# XXX Remove after pth-syscall becomes pth
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1
.endif
