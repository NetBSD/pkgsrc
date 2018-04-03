# $NetBSD: Makefile,v 1.2 2018/04/03 20:27:21 adam Exp $

DISTNAME=	txgithub-15.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txgithub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tomprince/txgithub
COMMENT=	GitHub API client using Twisted
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-twisted>=12.3.0:../../net/py-twisted

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} get-github-token get-github-token-${PYVERSSUFFIX} && \
		${MV} gist gist-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
