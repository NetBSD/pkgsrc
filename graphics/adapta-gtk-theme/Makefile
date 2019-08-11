# $NetBSD: Makefile,v 1.5 2019/08/11 13:21:07 wiz Exp $

DISTNAME=	adapta-gtk-theme-3.95.0.11
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=adapta-project/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/adapta-project/adapta-gtk-theme
COMMENT=	Adaptive Gtk+ theme based on Material Design
LICENSE=	gnu-gpl-v2 AND cc-by-sa-v4.0

EXTRACT_USING=	bsdtar
USE_TOOLS+=	autoconf automake bash gmake perl pkg-config
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-parallel
CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-cinnamon
CONFIGURE_ARGS+=	--disable-flashback

DEPENDS+=	gtk2-engines-murrine-[0-9]*:../../x11/gtk2-engines-murrine
TOOL_DEPENDS+=	inkscape-[0-9]*:../../graphics/inkscape
TOOL_DEPENDS+=	parallel-[0-9]*:../../parallel/parallel
TOOL_DEPENDS+=	sassc-[0-9]*:../../www/sassc

REPLACE_BASH+=	extra/tweetdeck/recolor-cdk.sh
REPLACE_BASH+=	gtk/asset/assets-gtk2-scripts/clone-assets-gtk2.sh
REPLACE_BASH+=	gtk/asset/assets-gtk2-scripts/recolor-assets-gtk2.sh
REPLACE_BASH+=	gtk/asset/assets-gtk2-scripts/render-assets-gtk2.sh
REPLACE_BASH+=	gtk/asset/assets-gtk3-scripts/recolor-assets-gtk3.sh
REPLACE_BASH+=	gtk/asset/assets-gtk3-scripts/render-assets-gtk3.sh
REPLACE_BASH+=	gtk/gtk-2.0/recolor-gtk2.sh
REPLACE_BASH+=	shell/asset/clone-assets-cinnamon.sh
REPLACE_BASH+=	shell/asset/clone-assets-gnome-shell.sh
REPLACE_BASH+=	shell/asset/clone-assets-xfce.sh
REPLACE_BASH+=	shell/asset/render-assets-cinnamon-thumb.sh
REPLACE_BASH+=	wm/asset/assets-metacity-scripts/clone-assets-metacity.sh
REPLACE_BASH+=	wm/asset/assets-metacity-scripts/render-assets-metacity.sh
REPLACE_BASH+=	wm/asset/assets-openbox-scripts/clone-assets-openbox.sh
REPLACE_BASH+=	wm/asset/assets-xfwm-scripts/recolor-assets-xfwm.sh
REPLACE_BASH+=	wm/asset/assets-xfwm-scripts/render-assets-xfwm.sh

SUBST_CLASSES+=		fix-cp
SUBST_STAGE.fix-cp=	pre-configure
SUBST_MESSAGE.fix-cp=	Replace cp -Rv with cp -R, since -v is non-standard.
SUBST_FILES.fix-cp+=	Makefile.am
SUBST_FILES.fix-cp+=	extra/Makefile.am
SUBST_FILES.fix-cp+=	gtk/Makefile.am
SUBST_FILES.fix-cp+=	shell/Makefile.am
SUBST_FILES.fix-cp+=	wm/Makefile.am
SUBST_SED.fix-cp=	-e 's,cp -Rv ,cp -R ,g'

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
