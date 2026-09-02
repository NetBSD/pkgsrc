# $NetBSD: Makefile,v 1.9 2026/09/02 19:04:03 wiz Exp $

DISTNAME=	stagit-gopher-1.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://codemadness.org/releases/stagit-gopher/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/stagit-gopher/file/README.html
COMMENT=	Static git page generator for gopher
LICENSE=	mit

USE_LANGUAGES=	c99

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	LIBGIT_INC=
MAKE_FLAGS+=	LIBGIT_LIB=-lgit2

.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
