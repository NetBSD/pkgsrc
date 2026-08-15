# $NetBSD: Makefile,v 1.23 2026/08/15 12:53:24 bsiegert Exp $

DISTNAME=	didder-1.3.0
PKGREVISION=	22
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=makew0rld/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/makew0rld/didder
COMMENT=	Extensive, fast, and accurate command-line image dithering tool
LICENSE=	gnu-gpl-v3

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
