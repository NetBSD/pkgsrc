# $NetBSD: Makefile,v 1.3 2022/01/04 20:54:48 wiz Exp $

DISTNAME=	euca2ools-3.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_GITHUB:=eucalyptus/}
GITHUB_PROJECT=	euca2ools
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	https://github.com/eucalyptus/euca2ools
COMMENT=	Command line tools to interact with Amazon Web Services
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requestbuilder>=0.6:../../net/py-requestbuilder
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.8:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

EGG_NAME=	${DISTNAME:C/-([^0-9])/_\1/g:S/.1$/_devel/}

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_MESSAGE.setup=	Fixing setup.
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,share/man,${PKGMANDIR},g'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
