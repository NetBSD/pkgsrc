# $NetBSD: Makefile,v 1.5 2010/02/10 19:17:38 joerg Exp $
#

DISTNAME=		jools-0.20
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://www.eecs.umich.edu/~pelzlpj/jools/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} jools-musicpack-1.0.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eecs.umich.edu/~pelzlpj/jools/
COMMENT=		Bejeweled clone

PKG_DESTDIR_SUPPORT=	user-destdir

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
