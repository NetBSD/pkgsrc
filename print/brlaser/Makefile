# $NetBSD: Makefile,v 1.17 2024/11/14 22:21:22 wiz Exp $

DISTNAME=		brlaser-6.2.6
PKGREVISION=		5
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GITHUB:=Owl-Maintain/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/Owl-Maintain/brlaser/
COMMENT=		CUPS driver for Brother laser printers
LICENSE=		gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c++
USE_CXX_FEATURES+=	c++11

.include "../../print/libcups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
