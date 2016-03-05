# $NetBSD: Makefile,v 1.46 2016/03/05 11:28:42 jperkin Exp $
#

DISTNAME=	im-ja-1.5
PKGREVISION=	43
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://im-ja.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://im-ja.sourceforge.net/
COMMENT=	Japanese input module for GTK2 and XIM server
#LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 # AND bsd?

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt pkg-config gmake

GCONF_SCHEMAS+=	im-ja.schemas

GTK2_IMMODULES=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"

SUBST_CLASSES+=		fixpkgcfg
SUBST_STAGE.fixpkgcfg=	pre-configure
SUBST_FILES.fixpkgcfg=	configure
SUBST_SED.fixpkgcfg=	-e 's|libpanelapplet-2.0|libgnomeui-2.0 libpanelapplet-2.0|g'

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
