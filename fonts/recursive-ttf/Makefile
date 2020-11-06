# $NetBSD: Makefile,v 1.2 2020/11/06 18:04:26 maya Exp $

GITHUB_PROJECT=	recursive
GITHUB_RELEASE=	1.030
DISTNAME=	recursive-beta_1_030--statics
PKGNAME=	recursive-ttf-1.030
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=arrowtype/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.recursive.design/
COMMENT=	Variable font family for code & UI
LICENSE=	ofl-v1.1

# \todo: Build from source.
# \todo: Build OTF (current static source choice only includes TTF)

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
