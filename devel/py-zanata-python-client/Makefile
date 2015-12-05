# $NetBSD: Makefile,v 1.6 2015/12/05 21:26:09 adam Exp $

DISTNAME=	zanata-python-client-1.3.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zanata/}
GITHUB_PROJECT=	zanata-python-client
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://zanata.org/
COMMENT=	Zanata translation service client written in Python
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib

# TypeError: can't concat bytes to str
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35
USE_LANGUAGES=	# none

SUBST_CLASSES+=			version
SUBST_STAGE.version=		pre-configure
SUBST_MESSAGE.version=		Setting version
SUBST_FILES.version+=		VERSION-GEN
SUBST_VARS.version+=		PKGVERSION_NOREV

# Generate version file to avoid runtime error.
pre-configure:
	cd ${WRKSRC}/zanataclient && ${SH} ../VERSION-GEN > VERSION-FILE

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
