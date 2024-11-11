# $NetBSD: Makefile,v 1.34 2024/11/11 07:27:52 wiz Exp $

DISTNAME=	mutagen-1.47.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mutagen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quodlibet/mutagen
COMMENT=	Audio metadata handling for Python
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=5.0.4:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.50.1:../../devel/py-hypothesis

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fixing man paths.
SUBST_FILES.manpath=	setup.py
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
