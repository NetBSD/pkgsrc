# $NetBSD: Makefile,v 1.13 2001/05/06 12:48:56 rh Exp $
#

DISTNAME=	SDL-1.2.0
CATEGORIES=	devel games
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer, a cross-platform multimedia library

BUILD_DEPENDS+= autoconf>=2.13:../../devel/autoconf
BUILD_DEPENDS+= automake>=1.4:../../devel/automake
BUILD_DEPENDS+= nasm>=0.98:../../devel/nasm
DEPENDS+=	pth>=1.4.0:../../devel/pth
#DEPENDS+=	unproven-pthreads>=0.16
DEPENDS+=	esound>=0.2.18:../../audio/esound

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_MESA=	YES
USE_X11=	YES
USE_LIBTOOL=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
NASMFLAGS=	-f elf
.else
NASMFLAGS=	-f aoutb
.endif

.ifdef SDL_USE_NAS
DEPENDS+=		nas>=1.4:../../audio/nas
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--disable-pthread-sem
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} -D_POSIX_THREAD_SYSCALL_SOFT=1"
CONFIGURE_ENV+=		NASMFLAGS="${NASMFLAGS}"
MAKE_ENV+=		NASMFLAGS="${NASMFLAGS}"
LDFLAGS+=		-Wl,-R${X11BASE}/lib -L${X11BASE}/lib
#CC=			${LOCALBASE}/pthreads/bin/pgcc

pre-patch:
	cd ${WRKSRC} && ${MKDIR} src/audio/netbsd

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf

post-configure:
	cd ${WRKSRC}/src/audio && ${CP} *.[ch] netbsd/

.include "../../mk/bsd.pkg.mk"
