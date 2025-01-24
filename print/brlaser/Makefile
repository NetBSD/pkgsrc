# $NetBSD: Makefile,v 1.18 2025/01/24 01:01:50 schmonz Exp $

DISTNAME=		brlaser-6.2.7
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GITHUB:=Owl-Maintain/}
GITHUB_TAG=		refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/Owl-Maintain/brlaser/
COMMENT=		CUPS driver for Brother laser printers
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_LANGUAGES=		c++
USE_CXX_FEATURES+=	c++11

.include "../../devel/cmake/build.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
