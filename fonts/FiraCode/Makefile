# $NetBSD: Makefile,v 1.9 2024/05/17 14:59:23 wiz Exp $

DISTNAME=	Fira_Code_v6.2
PKGNAME=	${DISTNAME:S/Fira_Code_v/FiraCode-/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=tonsky/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tonsky/FiraCode/
COMMENT=	Monospaced font with programming ligatures
LICENSE=	ofl-v1.1

NO_BUILD=		yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
