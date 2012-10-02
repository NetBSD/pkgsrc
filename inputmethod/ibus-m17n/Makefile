# $NetBSD: Makefile,v 1.18 2012/10/02 17:11:21 tron Exp $
#

DISTNAME=	ibus-m17n-1.3.4
PKGREVISION=	4
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	M17N engine for IBus platform
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt gmake

.include "../../devel/m17n-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
