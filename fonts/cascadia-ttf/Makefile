# $NetBSD: Makefile,v 1.1 2019/11/28 13:27:21 wiz Exp $

GITHUB_PROJECT=	cascadia-code
DISTNAME=	cascadia-ttf-1911.21
CATEGORIES=	fonts
MASTER_SITES=	https://github.com/microsoft/cascadia-code/releases/download/v${PKGVERSION_NOREV}/
DIST_SUBDIR=	${DISTNAME}
DISTFILES=	Cascadia.ttf
DISTFILES+=	CascadiaMono.ttf
DISTFILES+=	CascadiaMonoPL.ttf
DISTFILES+=	CascadiaPL.ttf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/cascadia-code/
COMMENT=	Microsoft Cascadia Code font
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	# none

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
