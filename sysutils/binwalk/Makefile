# $NetBSD: Makefile,v 1.5 2022/01/07 19:50:46 nikita Exp $

DISTNAME=	binwalk-2.3.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ReFirmLabs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ReFirmLabs/binwalk/
COMMENT=	Firmware analysis tool
LICENSE=	mit

# Version 2.2.1 did start deprecating python 2.7
PYTHON_VERSIONS_INCOMPATIBLE=	27
USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
