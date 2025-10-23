# $NetBSD: Makefile,v 1.61 2025/10/23 20:36:55 wiz Exp $

DISTNAME=	LibOFX%200.10.9
PKGNAME=	${DISTNAME:S/LibOFX%20/libofx-/}
PKGREVISION=	2
CATEGORIES=	finance devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libofx/}

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://libofx.sourceforge.net/
COMMENT=	OFX (Open Financial eXchange) Library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/libofx-libofx-d01712e

USE_LANGUAGES=		c c++11
USE_TOOLS+=		pkg-config

TEST_TARGET=	check

.include "../../devel/cmake/build.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
