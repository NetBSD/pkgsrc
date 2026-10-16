# $NetBSD: Makefile,v 1.10 2026/10/16 17:12:54 adam Exp $

DISTNAME=	argparse_manpage-4.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argparse-manpage/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/praiskup/argparse-manpage
COMMENT=	Build manual page from python's ArgumentParser object
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=0:../../devel/py-pip

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	argparse-manpage

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} share/man/man1/argparse-manpage.1 ${PKGMANDIR}/man1/argparse-manpage-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
