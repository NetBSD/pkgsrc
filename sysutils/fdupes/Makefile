# $NetBSD: Makefile,v 1.13 2026/04/08 12:30:10 wiz Exp $

DISTNAME=	fdupes-2.2.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=adrianlopezroche/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ef@math.uni-bonn.de
HOMEPAGE=	https://github.com/adrianlopezroche/fdupes
COMMENT=	Program for identifying or deleting duplicate files
LICENSE=	mit

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-implicit-function-declaration

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
