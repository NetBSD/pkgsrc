# $NetBSD: Makefile,v 1.1 2022/12/03 14:52:40 wiz Exp $

DISTNAME=	Mona.Sans.1.0
PKGNAME=	${DISTNAME:S/Mona.Sans./mona-sans-ttf-/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=github/}
GITHUB_PROJECT=	mona-sans
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/github/mona-sans/
COMMENT=	Mona Sans font from GitHub
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/"Mona Sans"

do-build:

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
