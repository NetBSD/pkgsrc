# $NetBSD: Makefile,v 1.21 2018/01/27 08:15:05 wen Exp $

DISTNAME=	mutagen-1.40.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mutagen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quodlibet/mutagen
COMMENT=	Audio metadata handling for Python
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fixing man paths.
SUBST_FILES.manpath=	setup.py
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
