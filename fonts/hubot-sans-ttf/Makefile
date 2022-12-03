# $NetBSD: Makefile,v 1.1 2022/12/03 14:56:33 wiz Exp $

DISTNAME=	Hubot.Sans.1.0
PKGNAME=	${DISTNAME:S/Hubot.Sans./hubot-sans-ttf-/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=github/}
GITHUB_PROJECT=	hubot-sans
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/github/hubot-sans/
COMMENT=	Hubot Sans font from GitHub
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/"Hubot Sans"

do-build:

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
