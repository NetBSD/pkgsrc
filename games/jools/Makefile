# $NetBSD: Makefile,v 1.1.1.1 2006/07/17 23:39:24 wiz Exp $
#

DISTNAME=		jools-0.20
CATEGORIES=		games
MASTER_SITES=		http://www.eecs.umich.edu/~pelzlpj/jools/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} jools-musicpack-1.0.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eecs.umich.edu/~pelzlpj/jools/
COMMENT=		Bejeweled clone

DEPENDS+=		${PYPKGPREFIX}-game>=1.4:../../devel/py-game

PYTHON_VERSIONS_ACCEPTED=	21 22 23 24
PYDISTUTILSPKG=			YES

post-install:
	${INSTALL_DATA} ${WRKDIR}/README ${PREFIX}/share/jools/music
	${INSTALL_DATA} ${WRKDIR}/timed/* ${PREFIX}/share/jools/music/timed
	${INSTALL_DATA} ${WRKDIR}/title/* ${PREFIX}/share/jools/music/title
	${INSTALL_DATA} ${WRKDIR}/untimed/* ${PREFIX}/share/jools/music/untimed

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
