# $NetBSD: Makefile,v 1.7 2008/01/05 23:33:23 heinz Exp $
#

DISTNAME=	libofx-0.8.3
PKGREVISION=	1
CATEGORIES=	finance devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libofx/}

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://libofx.sourceforge.net/
COMMENT=	OFX (Open Financial eXchange) Library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-opensp-includes=${BUILDLINK_PREFIX.opensp}/include/OpenSP \
			--with-opensp-libs=${BUILDLINK_PREFIX.opensp}/libs
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

.include "../../textproc/libxml++1/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
