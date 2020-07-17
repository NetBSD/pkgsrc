# $NetBSD: Makefile,v 1.2 2020/07/17 23:50:44 wiz Exp $

DISTNAME=	CascadiaCode-2007.01
PKGNAME=	${DISTNAME:S/CascadiaCode/cascadia-ttf/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	cascadia-code
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/cascadia-code/
COMMENT=	Microsoft Cascadia Code font
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	# none

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
