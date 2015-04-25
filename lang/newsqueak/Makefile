# $NetBSD: Makefile,v 1.1 2015/04/25 19:58:32 dholland Exp $

DISTNAME=	newsqueak
PKGNAME=	newsqueak-20000211
CATEGORIES=	lang
MASTER_SITES=	http://www.herpolhode.com/rob/

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	http://en.wikipedia.org/wiki/Newsqueak
COMMENT=	Newsqueak: a language for communicating with mice
LICENSE=	public-domain

WRKSRC=		${WRKDIR}
USE_TOOLS+=	yacc
INSTALLATION_DIRS=	bin share/squint/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/squint/squint \
		${DESTDIR}${PREFIX}/bin/squint
	${INSTALL_DATA} ${WRKSRC}/squint/include/*.h \
		${DESTDIR}${PREFIX}/share/squint/include/

.include "../../mk/bsd.pkg.mk"
