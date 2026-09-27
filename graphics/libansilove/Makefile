# $NetBSD: Makefile,v 1.36 2026/09/27 11:36:51 tnn Exp $

DISTNAME=	libansilove-1.4.2
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ansilove/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ansilove.org/
COMMENT=	Library for converting ANSI, ASCII, and other formats to PNG
LICENSE=	2-clause-bsd

FORCE_C_STD=		gnu99

.include "../../devel/cmake/build.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
