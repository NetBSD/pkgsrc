# $NetBSD: Makefile,v 1.2 2008/04/25 20:39:09 joerg Exp $
#

DISTNAME=		jools-0.20
CATEGORIES=		games
MASTER_SITES=		http://www.eecs.umich.edu/~pelzlpj/jools/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} jools-musicpack-1.0.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eecs.umich.edu/~pelzlpj/jools/
COMMENT=		Bejeweled clone

DEPENDS+=		${PYPKGPREFIX}-game>=1.4:../../devel/py-game

PYDISTUTILSPKG=			YES

post-install:
	${INSTALL_DATA} ${WRKDIR}/README ${PREFIX}/share/jools/music
	${INSTALL_DATA} ${WRKDIR}/timed/* ${PREFIX}/share/jools/music/timed
	${INSTALL_DATA} ${WRKDIR}/title/* ${PREFIX}/share/jools/music/title
	${INSTALL_DATA} ${WRKDIR}/untimed/* ${PREFIX}/share/jools/music/untimed

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
