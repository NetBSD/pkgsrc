# $NetBSD: Makefile,v 1.4 2021/04/30 18:03:21 rhialto Exp $

GITHUB_PROJECT=	recursive
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
DISTNAME=	ArrowType-Recursive-${PKGVERSION_NOREV}
PKGNAME=	recursive-ttf-1.078
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=arrowtype/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.recursive.design/
COMMENT=	Variable font family for code & UI
LICENSE=	ofl-v1.1

# \todo: Build from source.
# \todo: Install more of the fonts?

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/Recursive_Desktop/separate_statics/OTF

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
