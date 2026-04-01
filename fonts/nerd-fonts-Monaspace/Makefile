# $NetBSD: Makefile,v 1.1 2026/04/01 19:08:00 wiz Exp $
#
# Upstream provides nerd fonts variant themselves, so this package is
# not using the common nerd-fonts infrastructure.

DISTNAME=	monaspace-nerdfonts-v1.400
PKGNAME=	${DISTNAME:S,monaspace-nerdfonts-v,nerd-fonts-Monaspace-,}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=githubnext/}
GITHUB_PROJECT=	monaspace
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://monaspace.githubnext.com/
COMMENT=	Innovative superfamily of fonts for code
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/NerdFonts

NO_BUILD=	yes
NO_CONFIGURE=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
