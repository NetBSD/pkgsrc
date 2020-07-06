# $NetBSD: Makefile,v 1.7 2020/07/06 15:38:02 fcambus Exp $

DISTNAME=	fdupes-2.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=adrianlopezroche/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ef@math.uni-bonn.de
HOMEPAGE=	http://netdial.caribe.net/~adrian2/fdupes.html
COMMENT=	Program for identifying or deleting duplicate files
LICENSE=	mit

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
