# $NetBSD: Makefile,v 1.24 2026/07/06 18:24:29 wiz Exp $

DISTNAME=	lcov-2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=linux-test-project/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://github.com/linux-test-project/lcov
COMMENT=	Front-end for GCC's coverage testing tool gcov
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

USE_TOOLS+=	bash:run gmake perl

BUILD_TARGET=	doc

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}
MAKE_FLAGS+=	MAN_DIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	CFG_INST_DIR=${DESTDIR}${PREFIX}/share/examples/lcov

CONF_FILES=	${PREFIX}/share/examples/lcov/lcovrc \
		${PKG_SYSCONFDIR}/lcovrc

REPLACE_BASH+=	bin/checkstyle.sh
REPLACE_BASH+=	bin/copy_dates.sh
REPLACE_PERL+=	bin/fix.pl
REPLACE_PERL+=	bin/gendesc
REPLACE_PERL+=	bin/genhtml
REPLACE_PERL+=	bin/geninfo
REPLACE_PERL+=	bin/genpng
REPLACE_BASH+=	bin/get_changes.sh
REPLACE_BASH+=	bin/get_version.sh
REPLACE_PERL+=	bin/lcov
REPLACE_PERL+=	bin/llvm2lcov
REPLACE_PERL+=	bin/perl2lcov
REPLACE_PERL+=	scripts/*.pm
REPLACE_PERL+=	scripts/analyzeInfoFiles
REPLACE_PERL+=	scripts/criteria
REPLACE_PERL+=	scripts/get_signature
REPLACE_PERL+=	scripts/getp4version
REPLACE_PERL+=	scripts/gitblame
REPLACE_PERL+=	scripts/gitdiff
REPLACE_PERL+=	scripts/gitversion
REPLACE_PERL+=	scripts/p4annotate
REPLACE_PERL+=	scripts/p4udiff

REPLACE_PYTHON+=	bin/py2lcov
REPLACE_PYTHON+=	bin/xml2lcov
REPLACE_PYTHON+=	bin/xml2lcovutil.py
REPLACE_PYTHON+=	scripts/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
