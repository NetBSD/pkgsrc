# $NetBSD: Makefile,v 1.30 2026/02/04 00:06:54 wiz Exp $

GIT_VERSION=	20240206.1615ec326858f8c2bd8f30b3a86ea71830409ce4
DIST_VERSION=	0.1
DISTNAME=	gyp-${DIST_VERSION}pre${GIT_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/.[^.]*$//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gyp.gsrc.io/
COMMENT=	GYP can Generate Your Projects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

WRKSRC=		${WRKDIR}/gyp

WHEEL_NAME=	gyp-${DIST_VERSION}

# REPLACE_PYTHON settings farmed out due to size...
.include "replace-python.mk"

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Fix python invocation
SUBST_FILES.python+=	gyp
SUBST_FILES.python+=	test/compiler-override/gyptest-compiler-global-settings.py
SUBST_SED.python+=	-e 's,/usr/bin/python,${PYTHONBIN},g'
SUBST_SED.python+=	-e 's,\([^/]\)python,\1${PYTHONBIN},g'

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*bash[^ ]*
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash=	gyp

USE_TOOLS+=	bash:run

# for test
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

do-test:
	${RUN}cd ${WRKSRC}; LANG=C ${SETENV} ${TEST_ENV} ${PYTHONBIN} gyptest.py -a -f make --passed

.include "../../lang/python/wheel.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
