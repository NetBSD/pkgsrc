# $NetBSD: Makefile,v 1.7 2004/04/01 18:57:44 jmmv Exp $
#

DISTNAME=	gnome-speech-0.3.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-speech/0.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME 2 text-to-speech API

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-gtk-doc

PKGCONFIG_OVERRIDE+=    gnome-speech-1.0.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
