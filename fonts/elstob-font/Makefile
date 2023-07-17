# $NetBSD: Makefile,v 1.1 2023/07/17 13:23:33 wiz Exp $

DISTNAME=	Elstob_v2_100
PKGNAME=	elstob-font-2.100
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=psb1558/}
GITHUB_PROJECT=	Elstob-font
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/psb1558/Elstob-font/
COMMENT=	Variable font for medievalists
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/Elstob_font

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
