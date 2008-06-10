# $NetBSD: Makefile,v 1.1.1.1 2008/06/10 18:49:39 drochner Exp $
#

DISTNAME=	duckmaze-pc-0.2
PKGNAME=	duckmaze-0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=duckmaze/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://duckmaze.sourceforge.net/
COMMENT=	A puzzle

USE_LANGUAGES=	# none

DM= ${WRKDIR}/duckmaze

do-build:
	${ECHO} "#!/bin/sh" >${DM}
	${ECHO} "cd ${PREFIX}/share/duckmaze" >>${DM}
	${ECHO} "exec ${PYTHONBIN} duckmaze.py" >>${DM}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/duckmaze
	${CP} -r ${WRKSRC}/* ${PREFIX}/share/duckmaze
	${INSTALL_SCRIPT} ${DM} ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../devel/py-game/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
