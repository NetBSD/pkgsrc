# $NetBSD: Makefile,v 1.2 2024/11/24 19:53:46 adam Exp $

DISTNAME=	mail_parser-4.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mail-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SpamScope/mail-parser
COMMENT=	Wrapper for email standard library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.6.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>0:../../devel/py-test-mock

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} mail-parser mail-parser-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
