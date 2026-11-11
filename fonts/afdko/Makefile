# $NetBSD: Makefile,v 1.2 2026/11/11 11:53:10 wiz Exp $

DISTNAME=	afdko-4.0.3
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=adobe-type-tools/}
GITHUB_PROJECT=	afdko
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/adobe-type-tools/afdko/
COMMENT=	Adobe Font Development Kit for OpenType
LICENSE=	apache-2.0

USE_LANGUAGES+=	c c++

CFLAGS+=	-I${BUILDLINK_PREFIX.antlr4-cpp-runtime}/include/antlr4-runtime

.include "../../devel/cmake/build.mk"
.include "../../devel/antlr4-cpp-runtime/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
