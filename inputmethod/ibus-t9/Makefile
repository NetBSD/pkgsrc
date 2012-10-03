# $NetBSD: Makefile,v 1.11.2.1 2012/10/03 12:08:21 spz Exp $
#

DISTNAME=	ibus-t9-2.1.0.20100601
PKGREVISION=	12
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus-t9.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-t9/
COMMENT=	IBus T9 Input Method
LICENSE=	gnu-gpl-v3

DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
