# $NetBSD: Makefile,v 1.6 2022/01/04 20:54:11 wiz Exp $

DISTNAME=	email_validator-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/email-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JoshData/python-email-validator
COMMENT=	Robust email syntax and deliverability validation library
LICENSE=	cc0-1.0-universal

DEPENDS+=	${PYPKGPREFIX}-dns>=1.15.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-idna>=2.0.0:../../www/py-idna

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} email_validator email_validator-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
