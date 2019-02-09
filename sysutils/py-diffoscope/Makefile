# $NetBSD: Makefile,v 1.8 2019/02/09 14:13:25 khorben Exp $

DISTNAME=	diffoscope-110
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/diffoscope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://diffoscope.org/
COMMENT=	In-depth comparison of files, archives, and directories
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-libarchive-c-[0-9]*:../../archivers/py-libarchive-c
DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-tlsh-[0-9]*:../../devel/py-tlsh
DEPENDS+=	colordiff-[0-9]*:../../devel/colordiff
# for xxd
DEPENDS+=	vim-[0-9]*:../../editors/vim

USE_LANGUAGES=	# none
USE_TOOLS+=	bzip2:run gtar:run xz:run

SUBST_CLASSES+=		gtar
SUBST_SED.gtar+=	-e "s,'tar,'gtar,"
SUBST_FILES.gtar+=	diffoscope/comparators/tar.py
SUBST_FILES.gtar+=	tests/comparators/test_utils.py
SUBST_MESSAGE.gtar=	Fix path to gtar.
SUBST_STAGE.gtar=	post-configure

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} diffoscope diffoscope-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
