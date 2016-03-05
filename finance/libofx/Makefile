# $NetBSD: Makefile,v 1.19 2016/03/05 11:28:29 jperkin Exp $

DISTNAME=	libofx-0.9.10
PKGREVISION=	1
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
