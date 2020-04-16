# $NetBSD: Makefile,v 1.1 2020/04/16 17:35:47 joerg Exp $
#

GITHUB_PROJECT=	libobjc2
DISTNAME=	${GITHUB_PROJECT}-2.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnustep/}
GITHUB_TAG=	v2.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gnustep/libobjc2
COMMENT=	Objective-C runtime library
LICENSE=	mit

ONLY_FOR_COMPILER=	clang

USE_LANGUAGES=	c c++

USE_CMAKE=	yes

.include "../../mk/bsd.pkg.mk"
