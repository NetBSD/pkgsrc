# $NetBSD: Makefile,v 1.11 2000/11/15 13:52:58 wiz Exp $
#

VERS=		3.87
DISTNAME=	lame${VERS}beta
PKGNAME=	lame-${VERS}
WRKSRC=		${WRKDIR}/lame${VERS}
CATEGORIES=	audio
MASTER_SITES=	http://lame.sourceforge.net/download/beta/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.mp3dev.org/mp3/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
LICENSE=	fee-based-commercial-use

CONFIGURE_ARGS+=	--without-vorbis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/man/lame.1 ${PREFIX}/man/man1/lame.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/lame
	for f in contributors.html examples.html history.html id3.html	\
		index.html lame.css modes.html node5.html node6.html	\
		node7.html switchs.html; do				\
		${INSTALL_DATA} ${WRKSRC}/doc/html/$$f			\
			${PREFIX}/share/doc/html/lame;  		\
	done

.include "../../mk/bsd.prefs.mk"

.if defined(LAME_USE_GTK)
DEPENDS=		gtk+-1.2.*:../../x11/gtk
.else
CONFIGURE_ARGS+=	--enable-analyzer=no
.endif

.if (${MACHINE_ARCH} == "alpha")
DEPENDS+=	libffm-*:../../math/libffm
# double is faster than float on Alpha
CFLAGS+=	-O2 -Wall -fomit-frame-pointer -ffast-math -funroll-loops \
		-mfp-regs -fschedule-insns -fschedule-insns2 		  \
		-finline-functions -DFLOAT=double
# optimized libffm (free fast math library)
LIBS+=		-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lffm -lm
CONFIGURE_ENV+=	LIBS="${LIBS}"
.endif

.include "../../mk/bsd.pkg.mk"
