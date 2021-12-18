# $NetBSD: Makefile,v 1.12 2021/12/18 11:17:39 fcambus Exp $

DISTNAME=	CascadiaCode-2111.01
PKGNAME=	${DISTNAME:S/CascadiaCode/cascadia-ttf/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_PROJECT=	cascadia-code
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/cascadia-code/
COMMENT=	Microsoft Cascadia Code font
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
