# $NetBSD: Makefile,v 1.16 2006/01/24 07:32:29 wiz Exp $

DISTNAME=		ed2k-gtk-gui-0.6.3
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ed2k-gtk-gui/}

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://ed2k-gtk-gui.sourceforge.net/
COMMENT=		GUI for the eDonkey2000 and Overnet

USE_TOOLS+=		pkg-config
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CONFIGURE_LDFLAGS=${LDFLAGS:M*:Q}

SUBST_CLASSES+=		shell
SUBST_MESSAGE.shell=	"Fixing hardcoded shell."
SUBST_STAGE.shell=	post-patch
SUBST_FILES.shell=	ed2k_gui/misc.c
SUBST_SED.shell=	-e 's,/bin/bash,/bin/sh,g'

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
