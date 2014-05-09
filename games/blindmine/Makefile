# $NetBSD: Makefile,v 1.23 2014/05/09 07:37:06 wiz Exp $

DISTNAME=	blindmine-0.3-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	15
CATEGORIES=	games python
MASTER_SITES=	http://kldp.net/frs/download.php/3097/
EXTRACT_SUFX=	.zip

MAINTAINER=	fox9@netb.co.kr
HOMEPAGE=	http://blindmine.kldp.net/
COMMENT=	Minesweeper clone that you can play with your eyes closed

WRKSRC=		${WRKDIR}/${PKGBASE}
NO_CONFIGURE=	yes
NO_BUILD=	yes

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing paths.
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	blindmine.py sdl_ui.py
SUBST_SED.path=		-e 's,/usr/bin/env python,${PYTHONBIN},g'

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.3

INSTALLATION_DIRS=	bin share/doc/blindmine share/blindmine/data

.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/application.mk"

post-extract:
	( ${ECHO} "#!${SH}";						    \
	  ${ECHO} "cd ${PREFIX}/share/blindmine && ${PYTHONBIN} blindmine.py > /dev/null"    \
	) > ${WRKSRC}/blindmine
	${CHMOD} +x ${WRKSRC}/blindmine

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/blindmine ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/howto.txt ${DESTDIR}${PREFIX}/share/doc/blindmine
	${INSTALL_DATA} ${WRKSRC}/*.py ${DESTDIR}${PREFIX}/share/blindmine
	${INSTALL_DATA} ${WRKSRC}/data/* ${DESTDIR}${PREFIX}/share/blindmine/data
	${PYTHONBIN} ${PYCOMPILEALL} ${DESTDIR}${PREFIX}/share/blindmine
	${PYTHONBIN} -O ${PYCOMPILEALL} ${DESTDIR}${PREFIX}/share/blindmine

.include "../../mk/bsd.pkg.mk"
