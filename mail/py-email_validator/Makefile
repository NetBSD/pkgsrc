# $NetBSD: Makefile,v 1.7 2022/01/05 15:41:13 wiz Exp $

DISTNAME=	email_validator-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/email-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JoshData/python-email-validator
COMMENT=	Robust email syntax and deliverability validation library
LICENSE=	cc0-1.0-universal

DEPENDS+=	${PYPKGPREFIX}-dns>=1.15.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-idna>=2.0.0:../../www/py-idna

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} email_validator email_validator-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
