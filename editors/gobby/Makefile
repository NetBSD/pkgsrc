# $NetBSD: Makefile,v 1.24 2012/09/15 10:04:26 obache Exp $

DISTNAME=	gobby-0.4.12
PKGREVISION=	8
CATEGORIES=	editors
MASTER_SITES=	http://releases.0x539.de/gobby/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gobby.0x539.de/
COMMENT=	Collaborative Editor
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes

.include "options.mk"

.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../editors/obby/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/net6/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
