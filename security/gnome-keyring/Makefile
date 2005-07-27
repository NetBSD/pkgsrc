# $NetBSD: Makefile,v 1.9 2005/07/27 17:30:14 drochner Exp $
#

DISTNAME=	gnome-keyring-0.4.3
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-keyring/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME password and secret manager

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

PKGCONFIG_OVERRIDE=	${WRKSRC}/gnome-keyring-1.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
