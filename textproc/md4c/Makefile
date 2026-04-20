# $NetBSD: Makefile,v 1.4 2026/04/20 12:35:00 adam Exp $

DISTNAME=	md4c-0.5.3
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=mity/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mity/md4c/
COMMENT=	Markdown for C library and parser
LICENSE=	mit

WRKSRC=		${WRKDIR}/md4c-release-${PKGVERSION_NOREV}

PKGCONFIG_OVERRIDE+=	src/md4c-html.pc.in
PKGCONFIG_OVERRIDE+=	src/md4c.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
