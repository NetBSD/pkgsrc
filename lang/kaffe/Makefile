# $NetBSD: Makefile,v 1.11 1998/08/20 15:17:05 tsarna Exp $
#

DISTNAME=	kaffe-1.0.b1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.transvirtual.com/pub/kaffe/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.transvirtual.com/kaffe.html

DEPENDS+=	jpeg-6b:../../graphics/jpeg

CONFLICTS=	kaffe-0.9.2

ONLY_FOR_ARCHS=	alpha arm32 i386 m68k mips* sparc

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/ENVIRONMENT ${WRKSRC}/license.terms \
		${PREFIX}/share/kaffe

.include "../../mk/bsd.pkg.mk"
