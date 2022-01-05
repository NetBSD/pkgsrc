# $NetBSD: Makefile,v 1.14 2022/01/05 15:41:22 wiz Exp $

DISTNAME=	diffoscope-134
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/diffoscope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://diffoscope.org/
COMMENT=	In-depth comparison of files, archives, and directories
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-libarchive-c-[0-9]*:../../archivers/py-libarchive-c
DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-tlsh-[0-9]*:../../devel/py-tlsh
DEPENDS+=	colordiff-[0-9]*:../../devel/colordiff
# for xxd
DEPENDS+=	vim-[0-9]*:../../editors/vim

USE_LANGUAGES=	c  # for tests
USE_TOOLS+=	bzip2:run gtar:run xz:run

# Only Python 3 is supported.
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} diffoscope diffoscope-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
