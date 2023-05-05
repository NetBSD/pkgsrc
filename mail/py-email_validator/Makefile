# $NetBSD: Makefile,v 1.9 2023/05/05 10:07:57 wiz Exp $

DISTNAME=	email_validator-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/email-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JoshData/python-email-validator
COMMENT=	Robust email syntax and deliverability validation library
LICENSE=	cc0-1.0-universal

DEPENDS+=	${PYPKGPREFIX}-idna>=2.0.0:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} email_validator email_validator-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
