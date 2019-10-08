# $NetBSD: Makefile,v 1.6 2019/10/08 14:36:40 ryoon Exp $

DISTNAME=	gmime-3.2.4
PKGNAME=	${DISTNAME:S/gmime/gmime3/}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gmime/3.2/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spruce.sourceforge.net/gmime/
COMMENT=	Library for the creation and parsing of MIME messages (API v3)
LICENSE=	gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--disable-mono
PKGCONFIG_OVERRIDE+=	gmime.pc.in
TEST_TARGET=		check

BUILDLINK_DEPMETHOD.libgpg-error=	build

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
