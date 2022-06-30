# $NetBSD: Makefile,v 1.10 2022/06/30 11:18:33 nia Exp $
#

VER=		0.1
DISTNAME=	likepython_${VER}
PKGNAME=	likepython-${VER}
PKGREVISION=	5

CATEGORIES=	lang
MASTER_SITES=	http://www.staringispolite.com/likepython/
EXTRACT_SUFX=	.tgz

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www.staringispolite.com/likepython/
COMMENT=	OMG! It's like Python, but like, you know, casual!
LICENSE=	mit

WRKSRC=		${WRKDIR} # More than one possibility -- please check manually.

REPLACE_PYTHON=	likepython

SUBST_CLASSES+=			fix-runt-interp
SUBST_STAGE.fix-runt-interp=	pre-configure
SUBST_MESSAGE.fix-runt-interp=	Fixing runtime python interpreter path.
SUBST_FILES.fix-runt-interp=	likepython
SUBST_SED.fix-runt-interp=	-e '/call/s,python,${PYTHONBIN},g'


NO_BUILD=		yes

INSTALLATION_DIRS=	bin share/examples/likepython share/doc/likepython

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} likepython ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} README ${DESTDIR}${PREFIX}/share/doc/likepython
	cd ${WRKSRC} && ${INSTALL_DATA} hello_world.lp ${DESTDIR}${PREFIX}/share/examples/likepython

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
