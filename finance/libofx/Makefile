# $NetBSD: Makefile,v 1.51 2023/11/08 13:19:09 wiz Exp $

DISTNAME=	libofx-0.9.15
PKGREVISION=	13
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
