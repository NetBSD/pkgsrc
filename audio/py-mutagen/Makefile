# $NetBSD: Makefile,v 1.26 2021/11/20 20:07:10 bsiegert Exp $

DISTNAME=	mutagen-1.45.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mutagen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quodlibet/mutagen
COMMENT=	Audio metadata handling for Python
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONED_DEPENDENCIES=	test:test hypothesis:test

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fixing man paths.
SUBST_FILES.manpath=	setup.py
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
