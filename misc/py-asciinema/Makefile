# $NetBSD: Makefile,v 1.9 2023/08/07 13:39:29 adam Exp $

DISTNAME=	asciinema-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc multimedia python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asciinema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asciinema.org/
COMMENT=	Terminal session recorder
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>0:../../devel/py-wheel

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		fix-path
SUBST_STAGE.fix-path=	pre-configure
SUBST_MESSAGE.fix-path=	Fixing paths.
SUBST_FILES.fix-path=	setup.cfg
SUBST_SED.fix-path=	-e 's,share/doc/asciinema,share/doc/asciinema-${PYVERSSUFFIX},g'
SUBST_SED.fix-path+=	-e 's,share/man/man1,${PKGMANDIR}/man1,g'

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} asciinema asciinema-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
		${MV} asciinema.1 asciinema-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
