# $NetBSD: Makefile,v 1.39 2008/04/26 00:25:02 wiz Exp $
#

DISTNAME=	gnome-speech-0.4.19
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-speech/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME 2 text-to-speech API

USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# Disable Java support.
CONFIGURE_ARGS+=	JAVAC=no JAVA=no IDLJ=no JAB=no

PKGCONFIG_OVERRIDE+=	gnome-speech-1.0.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
