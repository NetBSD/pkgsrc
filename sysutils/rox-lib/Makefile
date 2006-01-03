# $NetBSD: Makefile,v 1.17 2006/01/03 15:50:07 rxg Exp $
#

DISTNAME=	rox-lib-2.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Shared code for ROX applications

DEPENDS+=	rox>=2.2.0:../../sysutils/rox
DEPENDS+=	${PYPKGPREFIX}-expat-0nb2:../../textproc/py-expat

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Lib2
DIST_SUBDIR=	rox

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	AppRun MakeDist
PYTHON_PATCH_SCRIPTS+=	python/make_docs.py
PYTHON_PATCH_SCRIPTS+=	tests/python/*.py

INSTALLATION_DIRS=	share/rox/ROX-Lib2

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	"Fixing hardcoded paths."
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	Help/findrox.py
SUBST_FILES.path+=	python/rox/basedir.py
SUBST_FILES.path+=	python/rox/choices.py
SUBST_FILES.path+=	tests/python/testbasedir.py
SUBST_FILES.path+=	tests/python/testchoices.py
SUBST_SED.path=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${PREFIX}/share/rox/ROX-Lib2

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
