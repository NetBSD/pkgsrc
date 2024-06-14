#	$NetBSD: Makefile,v 1.1 2024/06/14 14:13:33 riastradh Exp $
#

.include "../../devel/git-cinnabar/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-hg-cinnabarclone-${VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Mercurial extension to accelerate git-cinnabar clone

DEPENDS+=	${PYPKGPREFIX}-mercurial>=6.0:../../devel/py-mercurial

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

NO_CONFIGURE=	yes
NO_BUILD=	yes

PLIST_SUBST+=	PYSITELIB=${PYSITELIB:Q}
PLIST_SUBST+=	PYVERS=${PYVERSSUFFIX:S/.//}

INSTALLATION_DIRS+=	${PYSITELIB}/hgext3rd

do-install:
	${INSTALL_DATA} ${WRKSRC:Q}/mercurial/cinnabarclone.py \
		${DESTDIR:Q}${PREFIX:Q}/${PYSITELIB:Q}/hgext3rd
	${PY_COMPILE_ALL} ${DESTDIR:Q}${PREFIX:Q}/${PYSITELIB:Q}/hgext3rd
	${PY_COMPILE_O_ALL} ${DESTDIR:Q}${PREFIX:Q}/${PYSITELIB:Q}/hgext3rd

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
