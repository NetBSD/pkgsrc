# $NetBSD: Makefile,v 1.8 2020/11/26 16:07:11 nia Exp $

DISTNAME=	fdupes-2.1.2
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
