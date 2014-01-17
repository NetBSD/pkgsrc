# $NetBSD: Makefile,v 1.2 2014/01/17 14:35:06 wiz Exp $

VERSION=	1.0.1
DISTNAME=	v${VERSION}
PKGNAME=	${PYPKGPREFIX}-audioread-${VERSION}
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sampsyo/audioread/archive/
DIST_SUBDIR=	audioread

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sampsyo/audioread
COMMENT=	Audio file decoder
LICENSE=	mit

WRKSRC=		${WRKDIR}/audioread-${VERSION}
USE_LANGUAGES=	# none
EGG_NAME=	audioread-${VERSION}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
