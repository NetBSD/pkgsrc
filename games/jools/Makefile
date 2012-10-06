# $NetBSD: Makefile,v 1.8 2012/10/06 11:54:44 asau Exp $
#

DISTNAME=		jools-0.20
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		http://pessimization.com/software/jools/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} jools-musicpack-1.0.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pessimization.com/software/jools/
COMMENT=		Bejeweled clone

DEPENDS+=		${PYPKGPREFIX}-game>=1.4:../../devel/py-game

PYDISTUTILSPKG=			YES

post-install:
	${INSTALL_DATA} ${WRKDIR}/README ${DESTDIR}${PREFIX}/share/jools/music
	${INSTALL_DATA} ${WRKDIR}/timed/* ${DESTDIR}${PREFIX}/share/jools/music/timed
	${INSTALL_DATA} ${WRKDIR}/title/* ${DESTDIR}${PREFIX}/share/jools/music/title
	${INSTALL_DATA} ${WRKDIR}/untimed/* ${DESTDIR}${PREFIX}/share/jools/music/untimed

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
