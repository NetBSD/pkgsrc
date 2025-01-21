# $NetBSD: Makefile,v 1.2 2025/01/21 14:10:52 adam Exp $

DISTNAME=	huggingface_hub-0.27.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/huggingface-hub/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://huggingface.co/docs/huggingface_hub
COMMENT=	The official Python client for the Huggingface Hub
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-fsspec>=2023.5.0:../../sysutils/py-fsspec
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.9:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.42.1:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} huggingface-cli huggingface-cli-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
