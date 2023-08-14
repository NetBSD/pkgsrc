# $NetBSD: Makefile,v 1.9 2023/08/14 05:25:13 wiz Exp $

DISTNAME=	binwalk-2.3.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ReFirmLabs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ReFirmLabs/binwalk/
COMMENT=	Firmware analysis tool
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27
USE_LANGUAGES=	# none
# bug in 2.3.4 release
EGG_NAME=	binwalk-2.3.3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
