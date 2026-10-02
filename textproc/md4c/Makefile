# $NetBSD: Makefile,v 1.5 2026/10/02 05:16:33 adam Exp $

DISTNAME=	md4c-0.6.0
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=mity/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mity/md4c
COMMENT=	Markdown for C library and parser
LICENSE=	mit

PKGCONFIG_OVERRIDE+=	src/md4c-html.pc.in
PKGCONFIG_OVERRIDE+=	src/md4c.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
