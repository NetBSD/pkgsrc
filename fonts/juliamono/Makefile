# $NetBSD: Makefile,v 1.1 2022/04/14 09:10:19 wiz Exp $

DISTNAME=	JuliaMono
PKGNAME=	juliamono-0.044
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
