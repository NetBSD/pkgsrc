# $NetBSD: Makefile,v 1.1 2026/07/12 20:22:39 wiz Exp $

DISTNAME=	colorsym-v1.0.0
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=luisfrancisco/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://colorsym.com/
COMMENT=	Symbol font that makes colors identifiable by shape
LICENSE=	cc-by-sa-v4.0 AND ofl-v1.1

do-build:

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
