# $NetBSD: Makefile,v 1.1.1.1 2007/08/20 21:35:08 agc Exp $

DISTNAME=	bzr-0.90rc1
CATEGORIES=	devel
MASTER_SITES=	http://bazaar-vcs.org/releases/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/
COMMENT=	Yet another distributed Version Control System

PYTHON_VERSIONS_ACCEPTED=	24

PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	setup.py
SUBST_SED.config+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.config+=	-e "s|@PKGMANDIR@|${PKGMANDIR}|g"
SUBST_SED.config+=	-e "s|@PYSITELIB@|${PREFIX}/${PYSITELIB}|g"
SUBST_MESSAGE.config=	Fixing paths.

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py install

.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
