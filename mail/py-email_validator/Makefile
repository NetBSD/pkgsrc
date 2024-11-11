# $NetBSD: Makefile,v 1.14 2024/11/11 07:28:38 wiz Exp $

DISTNAME=	email_validator-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/email-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JoshData/python-email-validator
COMMENT=	Robust email syntax and deliverability validation library
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-idna>=2.0.0:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-dns>=2.0.0:../../net/py-dns

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} email_validator email_validator-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
