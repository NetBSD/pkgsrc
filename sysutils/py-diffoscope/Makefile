# $NetBSD: Makefile,v 1.3 2016/12/13 15:44:59 khorben Exp $

DISTNAME=	diffoscope-63
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
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

USE_TOOLS+=	gtar:run xz:run bzip2:run

USE_LANGUAGES=		# none

SUBST_CLASSES+=		gtar
SUBST_SED.gtar+=	-e "s,'tar,'gtar,"
SUBST_FILES.gtar+=	diffoscope/comparators/tar.py tests/comparators/test_utils.py
SUBST_MESSAGE.gtar=	Fix path to gtar.
SUBST_STAGE.gtar=	post-configure

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} diffoscope diffoscope-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
