# $NetBSD: Makefile,v 1.28 2018/12/13 19:51:51 adam Exp $

DISTNAME=	libofx-0.9.10
PKGREVISION=	10
CATEGORIES=	finance devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libofx/}

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://libofx.sourceforge.net/
COMMENT=	OFX (Open Financial eXchange) Library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-opensp-includes=${BUILDLINK_PREFIX.opensp}/include/OpenSP \
			--with-opensp-libs=${BUILDLINK_PREFIX.opensp}/libs
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

.include "../../textproc/libxml++1/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
