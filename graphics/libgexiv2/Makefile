# $NetBSD: Makefile,v 1.3 2010/12/03 16:51:04 drochner Exp $
#

DISTNAME=		libgexiv2-0.2.1
PKGREVISION=		1
CATEGORIES=		graphics devel
MASTER_SITES=		http://yorba.org/download/gexiv2/0.2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://trac.yorba.org/wiki/gexiv2
COMMENT=		GObject-based wrapper around the Exiv2 library
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		vala-[0-9]*:../../lang/vala

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake m4 pkg-config

CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--prefix=${PREFIX}

PKGCONFIG_OVERRIDE=	gexiv2.m4

.include "../../devel/glib2/buildlink3.mk"
# incompatible API changes in 0.21
BUILDLINK_API_DEPENDS.exiv2+= exiv2<0.21
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
