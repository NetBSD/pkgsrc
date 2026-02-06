# $NetBSD: Makefile,v 1.64 2026/02/06 10:04:43 wiz Exp $

DISTNAME=	LibOFX%200.10.9
PKGNAME=	${DISTNAME:S/LibOFX%20/libofx-/}
PKGREVISION=	4
CATEGORIES=	finance devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libofx/}

MAINTAINER=	gary@duzan.org
HOMEPAGE=	https://libofx.sourceforge.net/
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
