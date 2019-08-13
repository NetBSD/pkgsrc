# $NetBSD: Makefile,v 1.1 2019/08/13 11:46:43 gdt Exp $

GITHUB_PROJECT=	nodemcu-uploader
VERSION=	0.4.3
NBVERSION=
PKGNAME=	${GITHUB_PROJECT}-${VERSION}${NBVERSION}
DISTNAME=	v${VERSION}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=kmpm/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/kmpm/nodemcu-uploader/
COMMENT=	Tool to upload files to a nodemcu/ESP8266 device
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
EGG_INFODIR=	nodemcu_uploader-${VERSION}-py${PYVERSSUFFIX}.egg-info

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-serial>=2.7:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.10.10:../../devel/py-wrapt

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
