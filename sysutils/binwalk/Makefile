# $NetBSD: Makefile,v 1.1 2018/06/13 13:25:02 maya Exp $

GITHUB_PROJECT=	binwalk
DISTNAME=	v2.1.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/^v//}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ReFirmLabs/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ReFirmLabs/binwalk/
COMMENT=	Firmware analysis tool
LICENSE=	mit

WRKSRC=		${WRKDIR}/binwalk-2.1.1
USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
