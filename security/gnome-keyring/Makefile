# $NetBSD: Makefile,v 1.22 2006/04/17 13:46:09 wiz Exp $
#

DISTNAME=	gnome-keyring-0.4.9
PKGREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-keyring/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME password and secret manager

USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

PKGCONFIG_OVERRIDE=	${WRKSRC}/gnome-keyring-1.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
