# $NetBSD: Makefile,v 1.75 2024/02/25 11:11:55 gson Exp $

DISTNAME=	anita-2.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://www.gson.org/netbsd/anita/download/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://www.gson.org/netbsd/anita/
COMMENT=	Automated NetBSD Installation and Test Application
LICENSE=	isc

DEPENDS+=	cdrtools>=2.00.00.00:../../sysutils/cdrtools
DEPENDS+=	${PYPKGPREFIX}-pexpect>=2.1:../../devel/py-pexpect

USE_LANGUAGES=	#none

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
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
