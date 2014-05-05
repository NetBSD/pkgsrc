# $NetBSD: Makefile,v 1.28 2014/05/05 00:48:02 ryoon Exp $
#

DISTNAME=	ibus-input-pad-1.4.2
PKGREVISION=	1
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

CONFIGURE_ARGS+=	--disable-maintainer-mode

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/input-pad/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
