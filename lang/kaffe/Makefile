# $NetBSD: Makefile,v 1.19 1999/07/11 23:05:31 hubertf Exp $
#

DISTNAME=		kaffe-1.0.b3
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.transvirtual.com/pub/kaffe/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.transvirtual.com/

DEPENDS=		jpeg-6b:../../graphics/jpeg \
			png-1.0.3:../../graphics/png \
			giflib-3.0:../../graphics/giflib

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-mips* *-*-sparc

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
			LOCALBASE=${LOCALBASE}
MAKE_ENV=		PATH=${PATH}:${LOCALBASE}/bin:${X11BASE}/bin PREFIX=${PREFIX} \
			LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} \
			MOTIFLIB="${MOTIFLIB}" CFLAGS="${CFLAGS}"
CFLAGS+=		-Dunix -I${LOCALBASE}/include -I${X11BASE}/include

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/ENVIRONMENT ${WRKSRC}/license.terms \
		${PREFIX}/share/kaffe

.include "../../mk/bsd.pkg.mk"
