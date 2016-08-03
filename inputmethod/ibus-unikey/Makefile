# $NetBSD: Makefile,v 1.28 2016/08/03 10:22:59 adam Exp $
#

DISTNAME=	ibus-unikey-0.6.1
PKGREVISION=	14
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus-unikey.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-unikey/
COMMENT=	Vietnamese Input Method Engine for IBUS using Unikey IME
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config intltool msgfmt

CONFIGURE_ARGS+=	--with-gtk-version=3

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
