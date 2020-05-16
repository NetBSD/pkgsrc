# $NetBSD: Makefile,v 1.22 2020/05/16 08:50:22 adam Exp $

DISTNAME=	mutagen-1.40.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mutagen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quodlibet/mutagen
COMMENT=	Audio metadata handling for Python
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

PYTHON_VERSIONED_DEPENDENCIES=	pytest:test

USE_LANGUAGES=	# none

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fixing man paths.
SUBST_FILES.manpath=	setup.py
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'

.include "../../lang/python/distutils.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
