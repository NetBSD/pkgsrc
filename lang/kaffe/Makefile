# $NetBSD: Makefile,v 1.16 1999/03/04 14:59:24 tron Exp $
#

DISTNAME=	kaffe-1.0.b3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.transvirtual.com/pub/kaffe/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.transvirtual.com/kaffe.html

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	giflib-3.0:../../graphics/giflib

ONLY_FOR_ARCHS=	arm32 i386 m68k mips* sparc
NOT_FOR_ARCHS=	alpha	#assembler problems

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LOCALBASE=${LOCALBASE}
MAKE_ENV=	PATH=${PATH}:${LOCALBASE}/bin:${X11BASE}/bin PREFIX=${PREFIX} \
		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} \
		MOTIFLIB="${MOTIFLIB}" CFLAGS="${CFLAGS}"
CFLAGS+=	-Dunix -I${LOCALBASE}/include -I${X11BASE}/include

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/ENVIRONMENT ${WRKSRC}/license.terms \
		${PREFIX}/share/kaffe

.include "../../mk/bsd.pkg.mk"
