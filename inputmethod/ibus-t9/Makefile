# $NetBSD: Makefile,v 1.39 2023/01/29 21:16:55 ryoon Exp $
#

DISTNAME=	ibus-t9-2.1.0.20100601
PKGREVISION=	36
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus-t9.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/ibus-t9/
COMMENT=	IBus T9 Input Method
LICENSE=	gnu-gpl-v3

DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
