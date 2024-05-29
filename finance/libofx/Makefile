# $NetBSD: Makefile,v 1.53 2024/05/29 16:32:30 adam Exp $

DISTNAME=	libofx-0.9.15
PKGREVISION=	15
CATEGORIES=	finance devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libofx/}

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://libofx.sourceforge.net/
COMMENT=	OFX (Open Financial eXchange) Library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++11
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-opensp-includes=${BUILDLINK_PREFIX.opensp}/include/OpenSP
CONFIGURE_ARGS+=	--with-opensp-libs=${BUILDLINK_PREFIX.opensp}/libs
TEST_TARGET=		check

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

.include "../../textproc/libxml++/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
