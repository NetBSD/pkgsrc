# $NetBSD: Makefile,v 1.25 2013/10/23 12:33:37 obache Exp $
#

DISTNAME=	ibus-input-pad-1.4.0
PKGREVISION=	12
CATEGORIES=	inputmethod
MASTER_SITES=	http://input-pad.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/input-pad/
COMMENT=	Input Pad for IBus
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt xgettext msgmerge

CONFIGURE_ARGS+=	--with-gtk=3.0

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/input-pad/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
