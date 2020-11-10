# $NetBSD: Makefile,v 1.1 2020/11/10 18:28:17 nia Exp $

PKGNAME=	gnome3-0.0.0.20201110
CATEGORIES=	meta-pkgs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/gnome-3/
COMMENT=	Meta-package for the GNOME 3 desktop environment

META_PACKAGE=	yes

# GNOME has a concept of "Core Apps".
#
# We deliberately do not include the heavier ones (e.g. epiphany - web browser,
# evolution - email client with webkit dependency, totem - media player) where
# the user will probably have their own preferred program anyway.
#
# https://wiki.gnome.org/Design/Apps/

DEPENDS+=	adwaita-icon-theme-[0-9]*:../../graphics/adwaita-icon-theme
#DEPENDS+=	cheese-[0-9]*:../../graphics/cheese
DEPENDS+=	file-roller-[0-9]*:../../archivers/file-roller
DEPENDS+=	evince-[0-9]*:../../print/evince3
DEPENDS+=	dconf-[0-9]*:../../devel/dconf-editor
#DEPENDS+=	evolution-[0-9]*:../../mail/evolution
#DEPENDS+=	epiphany-[0-9]*:../../www/epiphany
DEPENDS+=	eog-[0-9]*:../../graphics/eog
#DEPENDS+=	gdm-[0-9]*:../../wip/gdm
DEPENDS+=	gedit-[0-9]*:../../editors/gedit
DEPENDS+=	gnome-backgrounds-[0-9]*:../../graphics/gnome-backgrounds
DEPENDS+=	gnome-calendar-[0-9]*:../../time/gnome-calendar
DEPENDS+=	gnome-calculator-[0-9]*:../../math/gnome-calculator
DEPENDS+=	gnome-characters-[0-9]*:../../sysutils/gnome-characters
DEPENDS+=	gnome-control-center-[0-9]*:../../sysutils/gnome-control-center
DEPENDS+=	gnome-dictionary-[0-9]*:../../textproc/gnome-dictionary
DEPENDS+=	gnome-font-viewer-[0-9]*:../../sysutils/gnome-font-viewer
DEPENDS+=	gnome-screenshot-[0-9]*:../../graphics/gnome-screenshot
DEPENDS+=	gnome-settings-daemon-[0-9]*:../../sysutils/gnome-settings-daemon
DEPENDS+=	gnome-session-[0-9]*:../../x11/gnome-session
DEPENDS+=	gnome-shell-[0-9]*:../../x11/gnome-shell
DEPENDS+=	gnome-terminal-[0-9]*:../../x11/gnome-terminal
DEPENDS+=	gnome-themes-standard-[0-9]*:../../graphics/gnome-themes-standard
DEPENDS+=	mutter-[0-9]*:../../wm/mutter
DEPENDS+=	nautilus-[0-9]*:../../sysutils/nautilus
DEPENDS+=	orca-[0-9]*:../../misc/orca
#DEPENDS+=	totem-[0-9]*:../../multimedia/totem
DEPENDS+=	yelp-[0-9]*:../../misc/yelp3

# Some missing applications that might make sense later:

# caribou
# seahorse
# zenity
# sushi
# gnome-power-manager
# gnome-keyring
# accerciser
# vino
# vinagre
# gnome-games
# gnome-color-manager
# gnote
# gnome-contacts
# gnome-search-tool
# gnome-system-log

.include "../../mk/bsd.pkg.mk"
