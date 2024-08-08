# $NetBSD: Makefile,v 1.2 2024/08/08 20:04:11 pin Exp $

DISTNAME=	JuliaMono
PKGNAME=	juliamono-0.056
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=cormullion/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cormullion/juliamono/
COMMENT=	Monospaced font with reasonable Unicode support
LICENSE=	ofl-v1.1

NO_BUILD=	yes

WRKSRC=		${WRKDIR}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
