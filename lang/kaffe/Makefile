# $NetBSD: Makefile,v 1.9 1998/07/16 13:02:34 frueauf Exp $
#

DISTNAME=	kaffe-1.0.b1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.transvirtual.com/pub/kaffe/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	jpeg-6b:../../graphics/jpeg

CONFLICTS=	kaffe-0.9.2

ONLY_FOR_ARCHS=	i386 sparc alpha m68k mips arm32

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/ENVIRONMENT ${WRKSRC}/license.terms \
		${PREFIX}/share/kaffe

.include "../../mk/bsd.pkg.mk"
