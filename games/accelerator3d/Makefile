# $NetBSD: Makefile,v 1.11 2020/03/20 11:57:39 nia Exp $

DISTNAME=	accelerator-0.1.1
PKGNAME=	${DISTNAME:S/accelerator/accelerator3d/}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=accelerator3d/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://accelerator3d.sourceforge.net/
COMMENT=	Fast-paced, 3D, first-person shoot/dodge-'em-up
LICENSE=	artistic

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=	${PYPKGPREFIX}-ode-[0-9]*:../../devel/py-ode
DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL

PYTHON_VERSIONS_ACCEPTED=	27 # py-ode

REPLACE_PYTHON+=		accelerator.py

NO_BUILD=	yes

ACCELERATOR3D_DATADIR=	${PREFIX}/share/${PKGBASE}

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	accelerator.py
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|'snd'|'${PREFIX}/share/${PKGBASE}'|"
SUBST_SED.prefix+=	-e "s|'gfx'|'${PREFIX}/share/${PKGBASE}'|"
SUBST_STAGE.prefix=	pre-install

INSTALLATION_DIRS+=	bin share/${PKGBASE}

do-install:
	${RUN} ${INSTALL_SCRIPT} ${WRKSRC}/accelerator.py ${DESTDIR}${PREFIX}/bin/accelerator3d
	${RUN} ${INSTALL_DATA} ${WRKSRC}/snd/* ${DESTDIR}${ACCELERATOR3D_DATADIR}
	${RUN} ${INSTALL_DATA} ${WRKSRC}/gfx/* ${DESTDIR}${ACCELERATOR3D_DATADIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
