# $NetBSD: Makefile,v 1.13 2012/09/07 19:16:55 adam Exp $
#

DISTNAME=	gtk-im-libthai-0.2.1
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/ \
		ftp://linux.thai.net/pub/ThaiLinux/software/libthai/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/gtk-im-libthai
COMMENT=	GTK+-2.0 Thai Input Module
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-gtk3

GTK2_IMMODULES=	yes
.include "../../x11/gtk2/modules.mk"

.include "../../devel/libthai/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
