# $NetBSD: Makefile,v 1.1 2019/10/10 12:38:40 fox Exp $

DISTNAME=	Glances-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Glances/}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://nicolargo.github.io/glances/
COMMENT=	Cross-platform curses-based monitoring tool
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-psutil>=5.3.0:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-cursespanel-[0-9]*:../../devel/py-cursespanel

USE_LANGUAGES=	# none

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Set correct prefix in setup.py
SUBST_FILES.prefix=	${WRKSRC}/setup.py
SUBST_VARS.prefix=	PREFIX
SUBST_VARS.prefix+=	PKGMANDIR

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/glances bin/glances${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/glances.1 ${PKGMANDIR}/man1/glances${PYVERSSUFFIX}.1 && \
	${MV} share/doc/glances share/doc/glances${PYVERSSUFFIX} && \
	${MV} share/examples/glances share/examples/glances${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
