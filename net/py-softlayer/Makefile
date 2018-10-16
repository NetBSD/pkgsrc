# $NetBSD: Makefile,v 1.7 2018/10/16 13:49:53 adam Exp $

DISTNAME=	SoftLayer-5.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/SoftLayer/softlayer/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SoftLayer/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/softlayer/softlayer-python
COMMENT=	SoftLayer API bindings for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=5:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=0.53:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-ptable>=0.9.2:../../textproc/py-ptable
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.4:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.7.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.22:../../www/py-urllib3

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} sl sl-${PYVERSSUFFIX} && \
		${MV} slcli slcli-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
