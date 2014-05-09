# $NetBSD: Makefile,v 1.21 2014/05/09 07:37:03 wiz Exp $

DISTNAME=	rox-lib-2.0.2
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/desktop/node/46
COMMENT=	Shared code for ROX applications

DEPENDS+=	rox>=2.2.0:../../sysutils/rox
DEPENDS+=	${PYPKGPREFIX}-expat>=0nb2:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-gtk2>=1.99.13:../../x11/py-gtk2

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Lib2
DIST_SUBDIR=	rox

NO_BUILD=	yes

USE_TOOLS+=	pax

REPLACE_PYTHON=	AppRun MakeDist
REPLACE_PYTHON+=	python/make_docs.py
REPLACE_PYTHON+=	tests/python/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2

INSTALLATION_DIRS=	share/rox/ROX-Lib2

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing hardcoded paths.
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	python/rox/basedir.py
SUBST_FILES.path+=	python/rox/choices.py
SUBST_FILES.path+=	tests/python/testbasedir.py
SUBST_FILES.path+=	tests/python/testchoices.py
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	post-patch
SUBST_FILES.lib=	Help/findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/rox/ROX-Lib2

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
