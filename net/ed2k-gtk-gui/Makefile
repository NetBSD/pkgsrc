# $NetBSD: Makefile,v 1.1.1.1 2004/02/20 03:49:26 minskim Exp $

DISTNAME=		ed2k-gtk-gui-0.6.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ed2k-gtk-gui/}

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://ed2k-gtk-gui.sourceforge.net/
COMMENT=		GUI for the eDonkey2000 and Overnet

DEPENDS+=		xdg-dirs>=1.0:../../misc/xdg-dirs

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		shell
SUBST_MESSAGE.shell=	"Fixing hardcoded shell."
SUBST_STAGE.shell=	post-patch
SUBST_FILES.shell=	ed2k_gui/misc.c
SUBST_SED.shell=	-e 's,/bin/bash,/bin/sh,g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
