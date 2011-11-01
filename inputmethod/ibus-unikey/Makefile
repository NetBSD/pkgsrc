# $NetBSD: Makefile,v 1.7 2011/11/01 06:01:52 sbd Exp $
#

DISTNAME=	ibus-unikey-0.5.1
PKGREVISION=	4
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus-unikey.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-unikey/
COMMENT=	Vietnamese Input Method Engine for IBUS using Unikey IME
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/pyversion.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
