# $NetBSD: Makefile,v 1.13 2012/09/15 19:12:55 dholland Exp $
#

DISTNAME=	duckmaze-pc-0.2
PKGNAME=	duckmaze-0.2
PKGREVISION=	11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=duckmaze/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://duckmaze.sourceforge.net/
COMMENT=	Puzzle game

PKG_DESTDIR_SUPPORT=user-destdir

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

DM= ${WRKDIR}/duckmaze

REPLACE_PYTHON=level.py level_editor.py mopelib/mopelib.py duckmaze.py

do-build:
	${ECHO} "#!/bin/sh" >${DM}
	${ECHO} "cd ${PREFIX}/share/duckmaze" >>${DM}
	${ECHO} "exec ${PYTHONBIN} duckmaze.py" >>${DM}
	${CHMOD} a-x ${WRKSRC}/levels/level_*

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/duckmaze
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/duckmaze
	${INSTALL_SCRIPT} ${DM} ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../devel/py-game/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
