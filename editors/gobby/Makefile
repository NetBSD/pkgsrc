# $NetBSD: Makefile,v 1.4 2008/01/18 05:06:32 tnn Exp $
#

DISTNAME=	gobby-0.4.5
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://releases.0x539.de/gobby/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://gobby.0x539.de/
COMMENT=	Collaborative Editor

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		gmake msgfmt pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../editors/obby/buildlink3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../net/net6/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
