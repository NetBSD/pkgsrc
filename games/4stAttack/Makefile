# $NetBSD: Makefile,v 1.1.1.1 2005/11/04 07:10:12 rillig Exp $
#

DISTNAME=		4stAttack-2.1.4
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=forcedattack/}

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://forcedattack.sourceforge.net/
COMMENT=		Game in which you have to try to out-smart your opponent

PYTHON_PATCH_SCRIPTS=	4stattack.py

FIND_EXCLUDE=	\( -name \*.orig -or -name \*.txt -or -name \*.pre -or -name GPL -or -name \*~ -or -name 4stattack \)

do-build:
	${CHMOD} 0555 ${WRKSRC}/4stattack.py
	${MV} ${WRKSRC}/4stattack ${WRKSRC}/4stattack.pre
	${SED} -e "s,@FAHOME@,${PREFIX}/share/${PKGBASE}," \
		${WRKSRC}/4stattack.pre > ${WRKSRC}/4stattack
	${PYTHONBIN} ${PREFIX}/${PYLIB}/compileall.py ${WRKSRC}
	${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/${PKGBASE}
	${INSTALL_SCRIPT} ${WRKSRC}/4stattack ${PREFIX}/bin
	cd ${WRKSRC} && ${FIND} . -type f -and \! ${FIND_EXCLUDE} \
		-print | ${PAX} -rw -pp -pm ${PREFIX}/share/${PKGBASE}

.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
