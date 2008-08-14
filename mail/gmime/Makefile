# $NetBSD: Makefile,v 1.20 2008/08/14 20:39:25 wiz Exp $
#

DISTNAME=	gmime-2.2.22
CATEGORIES=	mail
MASTER_SITES=	http://spruce.sourceforge.net/gmime/sources/v2.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spruce.sourceforge.net/gmime/
COMMENT=	Library for the creation and parsing of MIME messages

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--disable-mono
PKGCONFIG_OVERRIDE+=	gmime-2.0.pc.in
TEST_TARGET=		check

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
