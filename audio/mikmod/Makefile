# $NetBSD: Makefile,v 1.16 1999/04/15 20:39:39 tron Exp $
#

DISTNAME=	mikmod-3.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.freenet.tlh.fl.us/~amstpi/	\
		${MASTER_SITE_SUNSITE:=apps/sound/players/}

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://www.freenet.tlh.fl.us/~amstpi/mikmod.html

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

USE_GMAKE=	yes

post-patch:
	chmod a+x ${WRKSRC}/build-mikmod.netbsd.sh

do-build:
	@(cd ${WRKSRC}; ${SETENV} PREFIX=${PREFIX} ./build-mikmod.netbsd.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usercode/mikmod ${PREFIX}/bin
	#${INSTALL_MAN} ${WRKSRC}/docs/mikmod.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/mikmod
.for f in bugs.txt changes.txt future.txt mikmod.doc mikmod.txt tips.txt
	${INSTALL_DATA} ${WRKSRC}/docs/$f ${PREFIX}/share/doc/mikmod
.endfor

.include "../../mk/bsd.pkg.mk"
