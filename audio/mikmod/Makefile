# $NetBSD: Makefile,v 1.14 1999/02/20 22:48:24 hubertf Exp $
#

DISTNAME=	mikmod-3.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.freenet.tlh.fl.us/~amstpi/	\
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://www.freenet.tlh.fl.us/~amstpi/mikmod.html

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

USE_GMAKE=	yes

.include "../../mk/bsd.prefs.mk"

post-patch:
	chmod a+x ${WRKSRC}/build-mikmod.netbsd.sh

do-build:
	@(cd ${WRKSRC}; ${SETENV} PREFIX=${PREFIX} ./build-mikmod.netbsd.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usercode/mikmod ${PREFIX}/bin
	#${INSTALL_MAN} ${WRKSRC}/docs/mikmod.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mikmod
.for f in bugs.txt changes.txt future.txt mikmod.doc mikmod.txt tips.txt
	${INSTALL_DATA} ${WRKSRC}/docs/$f ${PREFIX}/share/doc/mikmod
.endfor
.endif

.include "../../mk/bsd.pkg.mk"
