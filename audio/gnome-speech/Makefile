# $NetBSD: Makefile,v 1.11 2004/09/12 21:56:48 jmmv Exp $
#

DISTNAME=	gnome-speech-0.3.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-speech/0.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
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

# Disable Java support.
CONFIGURE_ARGS+=	JAVAC=no JAVA=no IDLJ=no JAB=no

PKGCONFIG_OVERRIDE+=    gnome-speech-1.0.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
