# $NetBSD: Makefile,v 1.10 2025/08/06 14:53:59 ryoon Exp $

DISTNAME=	OTF-source-code-pro-2.042R-u_1.062R-i
PKGNAME=	${DISTNAME:S/OTF-source-code-pro-/sourcecodepro-fonts-/:C/R-u_[[:digit:]\.Ri\-]*//}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=adobe-fonts/}
GITHUB_PROJECT=	source-code-pro
GITHUB_RELEASE=	2.042R-u/1.062R-i/1.026R-vf
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://adobe-fonts.github.io/source-code-pro/
COMMENT=	Set of monospaced OpenType fonts designed for coding environments
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/OTF

NO_BUILD=		yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
