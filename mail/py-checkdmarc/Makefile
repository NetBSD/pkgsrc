# $NetBSD: Makefile,v 1.1 2022/08/24 10:18:34 wiz Exp $

DISTNAME=	checkdmarc-4.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=c/checkdmarc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/checkdmarc/
COMMENT=	Python module and command line parser for SPF and DMARC records
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dns>=2.0.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-expiringdict>=1.1.4:../../devel/py-expiringdict
DEPENDS+=	${PYPKGPREFIX}-pyleri>=1.3.2:../../devel/py-pyleri
DEPENDS+=	${PYPKGPREFIX}-publicsuffix2>=2.20191221:../../www/py-publicsuffix2
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-timeout-decorator>=0.4.1:../../devel/py-timeout-decorator

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} checkdmarc checkdmarc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
