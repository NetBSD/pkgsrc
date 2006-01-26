# $NetBSD: Makefile,v 1.3 2006/01/26 03:26:12 minskim Exp $
#

DISTNAME=	blindmine-0.3-src
PKGNAME=	${DISTNAME:S/-src//}
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
SUBST_MESSAGE.path=	"Fixing paths."
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	blindmine.py sdl_ui.py
SUBST_SED.path=		-e 's,/usr/bin/env python,${PYTHONBIN},g'

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/application.mk"

post-extract:
	( ${ECHO} "#!${SH}";						    \
	  ${ECHO} "cd ${PREFIX}/share/${PKGBASE} && ${PYTHONBIN} blindmine.py > /dev/null"    \
	) > ${WRKSRC}/blindmine
	${CHMOD} +x ${WRKSRC}/blindmine

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/blindmine ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/howto.txt ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.py ${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/${PKGBASE}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${PREFIX}/share/${PKGBASE}/data
	${PYTHONBIN} ${PYCOMPILEALL} ${PREFIX}/share/${PKGBASE}
	${PYTHONBIN} -O ${PYCOMPILEALL} ${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
