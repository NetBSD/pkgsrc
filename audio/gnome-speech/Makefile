# $NetBSD: Makefile,v 1.23 2006/01/24 07:31:53 wiz Exp $
#

DISTNAME=	gnome-speech-0.3.9
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-speech/0.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME 2 text-to-speech API

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-gtk-doc

# Disable Java support.
CONFIGURE_ARGS+=	JAVAC=no JAVA=no IDLJ=no JAB=no

PKGCONFIG_OVERRIDE+=    gnome-speech-1.0.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
