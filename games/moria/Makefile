# $NetBSD: Makefile,v 1.4 2000/03/16 12:57:13 wiz Exp $

DISTNAME=		um5.5.2
PKGNAME=		moria-5.5.2
CATEGORIES=		games
# The "offical" master site has lost the pub/Games directory.
#MASTER_SITES=		ftp://ftp.cis.ksu.edu/pub/Games/Moria/source/
MASTER_SITES=		ftp://ftp.funet.fi/pub/unix/games/moria/source/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		simonb@netbsd.org
HOMEPAGE=		http://www.math.lsa.umich.edu/~grabiner/moria.html

WRKSRC=			${WRKDIR}/umoria

do-configure:
	@${RM} -f ${WRKSRC}/*.[ch] ${WRKSRC}/Makefile
	@cd ${WRKSRC}; ${LN} -s source/* unix/* .

post-install:
	@if [ ! -f /var/games/moria.scores ]; then \
		${CP} -p ${PREFIX}/share/games/moria/scores.dist \
			/var/games/moria.scores ; \
	fi

.include "../../mk/bsd.pkg.mk"
