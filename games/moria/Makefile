# $NetBSD: Makefile,v 1.8 2003/07/17 21:39:03 grant Exp $

DISTNAME=		um5.5.2
PKGNAME=		moria-5.5.2
WRKSRC=			${WRKDIR}/umoria
CATEGORIES=		games
# The "offical" master site has lost the pub/Games directory.
#MASTER_SITES=		ftp://ftp.cis.ksu.edu/pub/Games/Moria/source/
MASTER_SITES=		ftp://ftp.funet.fi/pub/unix/games/moria/source/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www-math.bgsu.edu/~grabine/moria.html
COMMENT=		Rogue-like game with a different sense of scale than Rogue

do-configure:
	@${RM} -f ${WRKSRC}/*.[ch] ${WRKSRC}/Makefile
	@cd ${WRKSRC}; ${LN} -s source/* unix/* .

post-install:
	@if [ ! -f /var/games/moria.scores ]; then \
		${CP} -p ${PREFIX}/share/games/moria/scores.dist \
			/var/games/moria.scores ; \
	fi

.include "../../mk/bsd.pkg.mk"
