# $NetBSD: Makefile,v 1.2 2016/06/03 14:02:23 jakllsch Exp $

DISTNAME=	bmap-tools-3.2
CATEGORIES=	archivers sysutils
MASTER_SITES=	ftp://ftp.infradead.org/pub/bmap-tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://source.tizen.org/documentation/reference/bmaptool
COMMENT=	Block map tools
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

BUILD_DEPENDS+=       ${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
