# $NetBSD: Makefile,v 1.26 2024/05/15 13:00:30 nikita Exp $

DISTNAME=	diffoscope-266
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/diffoscope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://diffoscope.org/
COMMENT=	In-depth comparison of files, archives, and directories
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-libarchive-c-[0-9]*:../../archivers/py-libarchive-c
DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-tlsh-[0-9]*:../../devel/py-tlsh
DEPENDS+=	colordiff-[0-9]*:../../devel/colordiff
# for xxd
DEPENDS+=	vim-[0-9]*:../../editors/vim

USE_LANGUAGES=	c  # for tests
USE_TOOLS+=	bzip2:run gtar:run xz:run

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} diffoscope diffoscope-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
