# $NetBSD: Makefile,v 1.32 2023/08/14 05:24:54 wiz Exp $

DISTNAME=		todoman-4.0.0
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_PYPI:=t/todoman/}
#MASTER_SITES=		${MASTER_SITE_GITHUB:=pimutils/}
#GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pimutils/todoman
COMMENT=	Simple CalDav-based todo manager
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-log-[0-9]*:../../devel/py-click-log
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-icalendar>=4.0.3:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-parsedatetime-[0-9]*:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-tabulate-[0-9]*:../../textproc/py-tabulate
DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

# if zsh completion is used, jq is needed
#https://github.com/pimutils/todoman/issues/498
#DEPENDS+=	jq-[0-9]*:../../devel/jq

# TEST_DEPENDS
TOOL_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TOOL_DEPENDS+=	${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes
TOOL_DEPENDS+=	${PYPKGPREFIX}-flake8-import-order-[0-9]*:../../devel/py-flake8-import-order
TOOL_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TOOL_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		bin/todo
USE_LANGUAGES=			# none

# overwrite automatically generated file with recommended one, per
# "Notes for Packagers" in documentation
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/todo ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
# needed due to py-click
TEST_ENV+=	LC_ALL=en_US.UTF-8
