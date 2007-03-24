# $NetBSD: Makefile,v 1.11 2007/03/24 19:21:24 joerg Exp $

DISTNAME=		um5.5.2
PKGNAME=		moria-5.5.2
CATEGORIES=		games
# The "offical" master site has lost the pub/Games directory.
#MASTER_SITES=		ftp://ftp.cis.ksu.edu/pub/Games/Moria/source/
MASTER_SITES=		ftp://ftp.funet.fi/pub/unix/games/moria/source/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www-math.bgsu.edu/~grabine/moria.html
COMMENT=		Rogue-like game with a different sense of scale than Rogue

WRKSRC=			${WRKDIR}/umoria
MAKE_FLAGS+=		CURSES=-lncurses

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-configure:
	@${RM} -f ${WRKSRC}/*.[ch] ${WRKSRC}/Makefile
	@cd ${WRKSRC}; ${LN} -s source/* unix/* .

post-install:
	@if [ ! -f /var/games/moria.scores ]; then \
		${CP} -p ${PREFIX}/share/games/moria/scores.dist \
			/var/games/moria.scores ; \
	fi

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
