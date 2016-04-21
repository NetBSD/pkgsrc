# $NetBSD: Makefile,v 1.40 2016/04/21 13:40:04 jperkin Exp $

DISTNAME=	anita-1.39
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://www.gson.org/netbsd/anita/download/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.gson.org/netbsd/anita/
COMMENT=	Automated NetBSD Installation and Test Application
LICENSE=	isc

DEPENDS+=	cdrtools>=2.00.00.00:../../sysutils/cdrtools
DEPENDS+=	${PYPKGPREFIX}-pexpect>=2.1:../../devel/py-pexpect

USE_LANGUAGES=	#none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 1.34

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	setup.py
SUBST_SED.manpath=	-e 's,man/,${PKGMANDIR}/,g'

.include "options.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
