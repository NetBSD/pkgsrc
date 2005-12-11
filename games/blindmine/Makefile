# $NetBSD: Makefile,v 1.2 2005/12/11 09:40:40 wiz Exp $
#

DISTNAME=	    blindmine-0.01
PKGREVISION=	    1
CATEGORIES=	    games python
MASTER_SITES=	    http://kldp.net/frs/download.php/1378/
EXTRACT_SUFX=	    .zip

MAINTAINER=	    fox9@netb.co.kr
HOMEPAGE=	    http://blindmine.kldp.net/
COMMENT=	    Minesweeper clone that you can play with your eyes closed

WRKSRC=		    ${WRKDIR}
NO_CONFIGURE=	    yes
NO_BUILD=	    yes

SUBST_CLASSES+=         path
SUBST_MESSAGE.path=     "Fixing paths."
SUBST_STAGE.path=       post-patch
SUBST_FILES.path=       dist/pysweeper.py dist/sdl_ui.py
SUBST_SED.path=         -e 's,/usr/bin/env python,${PYTHONBIN},g'

PYCOMPILEALL=   ${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/application.mk"

post-extract:
	( ${ECHO} "#!${SH}";						    \
	  ${ECHO} "cd ${PREFIX}/share/${PKGBASE} && ${PYTHONBIN} pysweeper.py > /dev/null"    \
	) > ${WRKSRC}/blindmine
	${CHMOD} +x ${WRKSRC}/blindmine

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/blindmine ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/howto.txt ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/dist/*.py ${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/${PKGBASE}/data
	${INSTALL_DATA} ${WRKSRC}/dist/data/* ${PREFIX}/share/${PKGBASE}/data
	${PYTHONBIN} ${PYCOMPILEALL} ${PREFIX}/share/${PKGBASE}
	${PYTHONBIN} -O ${PYCOMPILEALL} ${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
