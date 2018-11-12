# $NetBSD: Makefile,v 1.42 2018/11/12 03:52:22 ryoon Exp $
#

DISTNAME=	ibus-m17n-1.3.4
PKGREVISION=	25
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	M17N engine for IBus platform
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt gmake

.include "../../devel/m17n-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
