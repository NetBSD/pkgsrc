# $NetBSD: Makefile,v 1.2 2006/06/06 19:14:24 joerg Exp $
#

DISTNAME=	libofx-0.8.0
CATEGORIES=	finance devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libofx/}

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://libofx.sourceforge.net/
COMMENT=	OFX (Open Financial eXchange) Library

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-opensp-includes=${BUILDLINK_PREFIX.opensp}/include/OpenSP \
			--with-opensp-libs=${BUILDLINK_PREFIX.opensp}/libs
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

.include "../../textproc/opensp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
