# $NetBSD: Makefile,v 1.12 2010/02/10 19:17:38 joerg Exp $
#

DISTNAME=		4stAttack-2.1.4
PKGREVISION=		8
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=forcedattack/}

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://forcedattack.sourceforge.net/
COMMENT=		Game in which you have to try to out-smart your opponent

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin share/${PKGBASE}

USE_TOOLS+=	pax

PYTHON_PATCH_SCRIPTS=	4stattack.py

FIND_EXCLUDE=	\( -name \*.orig -or -name \*.txt -or -name \*.pre -or -name GPL -or -name \*~ -or -name 4stattack \)

do-build:
	${CHMOD} 0555 ${WRKSRC}/4stattack.py
	${MV} ${WRKSRC}/4stattack ${WRKSRC}/4stattack.pre
	${SED} -e "s,@FAHOME@,${PREFIX}/share/${PKGBASE}," \
		${WRKSRC}/4stattack.pre > ${WRKSRC}/4stattack
	${PY_COMPILE_ALL} ${WRKSRC}
	${PY_COMPILE_O_ALL} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/4stattack ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${FIND} . -type f -and \! ${FIND_EXCLUDE} \
		-print | pax -rw -pp -pm ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
