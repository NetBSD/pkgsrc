# $NetBSD: Makefile,v 1.8 2004/10/03 00:17:51 tv Exp $

DISTNAME=		ed2k-gtk-gui-0.6.2
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ed2k-gtk-gui/}

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://ed2k-gtk-gui.sourceforge.net/
COMMENT=		GUI for the eDonkey2000 and Overnet

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_X11=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CONFIGURE_LDFLAGS=${LDFLAGS:Q}

SUBST_CLASSES+=		shell
SUBST_MESSAGE.shell=	"Fixing hardcoded shell."
SUBST_STAGE.shell=	post-patch
SUBST_FILES.shell=	ed2k_gui/misc.c
SUBST_SED.shell=	-e 's,/bin/bash,/bin/sh,g'

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
