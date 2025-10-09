# $NetBSD: Makefile,v 1.80 2025/10/09 12:35:17 wiz Exp $

DISTNAME=	anita-2.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.gson.org/netbsd/anita/download/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://www.gson.org/netbsd/anita/
COMMENT=	Automated NetBSD Installation and Test Application
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	cdrtools>=2.00.00.00:../../sysutils/cdrtools
DEPENDS+=	${PYPKGPREFIX}-pexpect>=2.1:../../devel/py-pexpect

USE_LANGUAGES=	#none

REPLACE_PYTHON+=	anita

# AttributeError: module 'urllib.request' has no attribute 'FancyURLopener'
PYTHON_VERSIONS_INCOMPATIBLE=	314

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != man
SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	setup.py
SUBST_SED.manpath=	-e 's,man/,${PKGMANDIR}/,g'
.endif

do-test:
	${TRUE}		# Tests not integrated into pkgsrc

.include "options.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
