# $NetBSD: Makefile,v 1.12 2012/09/07 19:16:56 adam Exp $
#

DISTNAME=	ibus-unikey-0.6.1
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus-unikey.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-unikey/
COMMENT=	Vietnamese Input Method Engine for IBUS using Unikey IME
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config intltool msgfmt

CONFIGURE_ARGS+=	--with-gtk-version=2

.include "../../inputmethod/ibus/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
