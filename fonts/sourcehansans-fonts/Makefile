# $NetBSD: Makefile,v 1.5 2023/06/26 15:29:13 pho Exp $

DISTNAME=	SourceHanSansOTC
PKGNAME=	sourcehansans-fonts-2.004
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=adobe-fonts/}
GITHUB_PROJECT=	source-han-sans
GITHUB_RELEASE=	${PKGVERSION_NOREV}R
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/adobe-fonts/source-han-sans
COMMENT=	Set of Pan-CJK fonts from Adobe
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
