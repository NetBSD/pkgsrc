# $NetBSD: Makefile,v 1.19 2019/04/26 13:13:49 maya Exp $

GIT_VERSION=	20161117.940a15ee3f1c89f193cb4c19373b3f6e9ad15b95
DIST_VERSION=	0.1
DISTNAME=	gyp-${DIST_VERSION}pre${GIT_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gyp.gsrc.io/
COMMENT=	GYP can Generate Your Projects
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=   36 37 # not yet ported as of 0.1pre20161117.940a15ee3f1c89f193cb4c19373b3f6e9ad15b95
EGG_NAME=	gyp-${DIST_VERSION}

WRKSRC=		${WRKDIR}/gyp

# REPLACE_PYTHON settings farmed out due to size...
.include "Makefile.replace-python"

SUBST_CLASSES+=	python
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
