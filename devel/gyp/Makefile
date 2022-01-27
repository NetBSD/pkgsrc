# $NetBSD: Makefile,v 1.27 2022/01/27 18:48:47 wiz Exp $

GIT_VERSION=	20210830.d6c5dd51dc3a60bf4ff32a5256713690a1a10376
DIST_VERSION=	0.1
DISTNAME=	gyp-${DIST_VERSION}pre${GIT_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gyp.gsrc.io/
COMMENT=	GYP can Generate Your Projects
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}

EGG_NAME=	gyp-${DIST_VERSION}

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

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

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
