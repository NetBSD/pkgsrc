# $NetBSD: Makefile,v 1.6 2022/06/27 06:04:14 taca Exp $

VERSION=	2.001
DISTNAME=	public-sans-v${VERSION}
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=uswds/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uswds/public-sans/
COMMENT=	Strong, neutral typeface for text or display
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
