# $NetBSD: Makefile,v 1.1 2013/04/02 10:44:41 drochner Exp $
#

DISTNAME=	v1.0.0
PKGNAME=	${PYPKGPREFIX}-audioread-1.0.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sampsyo/audioread/archive/
DIST_SUBDIR=	audioread

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sampsyo/audioread
COMMENT=	Audio file decoder
LICENSE=	mit

WRKSRC=		${WRKDIR}/audioread-1.0.0
USE_LANGUAGES=	# none
EGG_NAME=	audioread-1.0.0

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
