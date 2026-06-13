# $NetBSD: Makefile,v 1.2 2026/06/13 15:34:38 wiz Exp $

DISTNAME=	Amiri-1.003
PKGNAME=	${DISTNAME:S/Amiri/amiri-ttf/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=aliftype/}
GITHUB_PROJECT=	amiri
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.amirifont.org/
COMMENT=	Classic Arabic typeface in Nasksh style
LICENSE=	ofl-v1.1

NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
