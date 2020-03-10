# $NetBSD: Makefile,v 1.73 2020/03/10 22:10:20 wiz Exp $
#

DISTNAME=	im-ja-1.5
PKGREVISION=	69
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://im-ja.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://im-ja.sourceforge.net/
COMMENT=	Japanese input module for GTK2 and XIM server
#LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 # AND bsd?

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt pkg-config gmake

GCONF_SCHEMAS+=	im-ja.schemas

GTK2_IMMODULES=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-gnome

.include "options.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
