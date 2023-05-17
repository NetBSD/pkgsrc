# $NetBSD: Makefile,v 1.1 2023/05/17 15:42:58 wiz Exp $

DISTNAME=	otf
PKGNAME=	intel-one-mono-1.0.0
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_RELEASE=	V${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/intel/intel-one-mono/
COMMENT=	Intel One Mono font
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/otf
USE_LANGUAGES=	# none

do-build:

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
