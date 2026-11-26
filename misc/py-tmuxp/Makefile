# $NetBSD: Makefile,v 1.8 2026/11/26 22:49:18 kim Exp $

DISTNAME=	tmuxp-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmux-python/}
GITHUB_PROJECT=	tmuxp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tmuxp.git-pull.com/
COMMENT=	Session manager for tmux
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-libtmux>=0.68:../../misc/py-libtmux
DEPENDS+=	${PYPKGPREFIX}-yaml>=6:../../textproc/py-yaml
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.29:../../devel/py-hatchling
# shtab imports tmuxp to generate the shell completions at build time
TOOL_DEPENDS+=	${PYPKGPREFIX}-shtab>=1.13:../../devel/py-shtab
TOOL_DEPENDS+=	${PYPKGPREFIX}-libtmux>=0.68:../../misc/py-libtmux
TOOL_DEPENDS+=	${PYPKGPREFIX}-yaml>=6:../../textproc/py-yaml
# codecov
# coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=0:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=0:../../textproc/py-sphinx

# as of 1.82.0, with the package installed
# 2 failed, 907 passed, 2 skipped, 5 rerun

PYTHON_VERSIONS_INCOMPATIBLE=	311

USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/src
# docs/conf.py imports gp_sphinx, which is not packaged
TEST_ENV+=	PYTEST_ADDOPTS=--ignore=docs/conf.py

PY_RENAME_BINARIES=	tmuxp
PYTHON_SELF_CONFLICT=	yes # completion files

COMPLETION_SHELLS=	bash fish zsh
COMPLETION_ENV=		NO_COLOR=1
COMPLETION_ENV+=	PYTHON_COLORS=0
COMPLETION_ENV+=	PYTHONDONTWRITEBYTECODE=1
COMPLETION_ENV+=	PYTHONPATH=${WRKSRC}/src

INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

# libtmux separates tmux format fields with a non-ASCII character, which
# tmux replaces with "_" unless the locale is UTF-8.  The locale has to
# come after TEST_ENV, which ends with LC_ALL=C from MAKE_ENV.
do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} LC_ALL=en_US.UTF-8 \
		pytest-${PYVERSSUFFIX}

post-build:
.for s in ${COMPLETION_SHELLS}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${COMPLETION_ENV} \
		${TOOL_PYTHONBIN} \
		-m shtab --shell=${s} --error-unimportable \
		--output=${WRKDIR}/tmuxp.${s} tmuxp.cli.create_parser
.endfor

post-install:
	${INSTALL_DATA} ${WRKDIR}/tmuxp.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/tmuxp
	${INSTALL_DATA} ${WRKDIR}/tmuxp.fish \
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/tmuxp.fish
	${INSTALL_DATA} ${WRKDIR}/tmuxp.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_tmuxp

.include "version.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
