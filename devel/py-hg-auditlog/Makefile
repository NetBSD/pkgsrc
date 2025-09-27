# $NetBSD: Makefile,v 1.2 2025/09/27 11:35:40 joerg Exp $
#

DISTNAME=	auditlog-0.1
PKGNAME=	${PYPKGPREFIX}-hg_${DISTNAME:S/_/-/}
CATEGORIES=	devel scm
MASTER_SITES=	https://www.NetBSD.org/~joerg/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.NetBSD.org
COMMENT=	Experimental audit trail extension for Mercurial
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.4nb1:../../devel/py-mercurial
USE_TOOLS+=	bash:test

INSTALLATION_DIRS+=	${PREFIX}/${PYSITELIB}/hgext3rd

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/auditlog.py ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/

.if 0
HG_WRKSRC=	cd ../py-mercurial && ${MAKE} show-var VARNAME=WRKSRC

do-test:
	HGROOT=${HG_WRKSRC:sh}; cd ${WRKSRC} && ${PYTHONBIN} $${HGROOT}/tests/run-tests.py ${_MAKE_JOBS:Q}
.endif

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
