# $NetBSD: dirs.mk,v 1.4 2009/06/14 22:58:05 joerg Exp $
#

.if !defined(DIRS_KDE4_MK)
DIRS_KDE4_MK=	#defined

_USE_XDG_DIRS=	1.2
.include "../../misc/xdg-dirs/dirs.mk"

KDE4_DIRS=	include/KDE
KDE4_DIRS+=	include/dom
KDE4_DIRS+=	include/kparts
KDE4_DIRS+=	include/solid
KDE4_DIRS+=	lib/kconf_update_bin
KDE4_DIRS+=	lib/kde4
KDE4_DIRS+=	lib/kde4/libexec
KDE4_DIRS+=	lib/kde4/plugins
KDE4_DIRS+=	lib/kde4/plugins/designer
KDE4_DIRS+=	lib/kde4/plugins/styles
KDE4_DIRS+=	share/applications/kde4
KDE4_DIRS+=	share/doc/kde
KDE4_DIRS+=	share/doc/kde/HTML

.for lang in af ar az bg bn br bs ca cs cy da de el en en_GB eo es et eu \
	fa fi fr fy ga gl he hi hr hu is it ja kk km ko lt lv mk mn ms \
	nb nds nl nn pa pl pt pt_BR ro ru rw se sk sl sr sr@Latn ss sv \
	ta tg tr uk uz vi zh_CN zh_TW
KDE4_DIRS+=	share/doc/kde/HTML/${lang}
KDE4_DIRS+=	share/doc/kde/HTML/${lang}/common
.endfor

KDE4_DIRS+=	share/doc/kde/HTML/en/kcontrol

_ICONCOLORS=	crystalsvg locolor oxygen
_ICONSIZES=	16x16 22x22 32x32 48x48 64x64 128x128 scalable
_ICONDIRS=	animations actions apps categories devices emblems 
_ICONDIRS+=	emotes filesystems intl mimetypes places status

.for color in ${_ICONCOLORS}
KDE4_DIRS+=	share/icons/${color}
.  for size in ${_ICONSIZES}
KDE4_DIRS+=	share/icons/${color}/${size}
.    for dir in ${_ICONDIRS}
KDE4_DIRS+=	share/icons/${color}/${size}/${dir}
.    endfor
.  endfor
.endfor

KDE4_DIRS+=	share/dbus-1/interfaces
KDE4_DIRS+=	share/emoticons

KDE4_DIRS+=	share/kde
KDE4_DIRS+=	share/kde/apps
KDE4_DIRS+=	share/kde/apps/cmake
KDE4_DIRS+=	share/kde/apps/cmake/modules
KDE4_DIRS+=	share/kde/apps/color-schemes
KDE4_DIRS+=	share/kde/apps/desktoptheme
KDE4_DIRS+=	share/kde/apps/desktoptheme/default
KDE4_DIRS+=	share/kde/apps/desktoptheme/default/widgets
KDE4_DIRS+=	share/kde/apps/kabc
KDE4_DIRS+=	share/kde/apps/kabc/formats
KDE4_DIRS+=	share/kde/apps/katepart
KDE4_DIRS+=	share/kde/apps/katepart/syntax
KDE4_DIRS+=	share/kde/apps/kcm_componentchooser
KDE4_DIRS+=	share/kde/apps/kcharselect
KDE4_DIRS+=	share/kde/apps/kconf_update
KDE4_DIRS+=	share/kde/apps/kcontrol
KDE4_DIRS+=	share/kde/apps/kcontrol/pics
KDE4_DIRS+=	share/kde/apps/kdesktop
KDE4_DIRS+=	share/kde/apps/kdesktop/programs
KDE4_DIRS+=	share/kde/apps/kdm
KDE4_DIRS+=	share/kde/apps/kdm/pics
KDE4_DIRS+=	share/kde/apps/kdm/pics/users
KDE4_DIRS+=	share/kde/apps/khangman
KDE4_DIRS+=	share/kde/apps/khtml
KDE4_DIRS+=	share/kde/apps/khtml/kpartplugins
KDE4_DIRS+=	share/kde/apps/kicker
KDE4_DIRS+=	share/kde/apps/kicker/applets
KDE4_DIRS+=	share/kde/apps/klettres
KDE4_DIRS+=	share/kde/apps/konqueror
KDE4_DIRS+=	share/kde/apps/konqsidebartng
KDE4_DIRS+=	share/kde/apps/konqsidebartng/virtual_folders
KDE4_DIRS+=	share/kde/apps/konqsidebartng/virtual_folders/services
KDE4_DIRS+=	share/kde/apps/kstyle
KDE4_DIRS+=	share/kde/apps/kstyle/themes
KDE4_DIRS+=	share/kde/apps/ktuberling
KDE4_DIRS+=	share/kde/apps/ktuberling/sounds
KDE4_DIRS+=	share/kde/apps/kvtml
KDE4_DIRS+=	share/kde/apps/kwin
KDE4_DIRS+=	share/kde/apps/kworldclock
KDE4_DIRS+=	share/kde/apps/kworldclock/maps
KDE4_DIRS+=	share/kde/apps/nepomuk
KDE4_DIRS+=	share/kde/apps/nepomuk/ontologies
KDE4_DIRS+=	share/kde/apps/nepomuk/pics
KDE4_DIRS+=	share/kde/apps/remoteview
KDE4_DIRS+=	share/kde/autostart
KDE4_DIRS+=	share/kde/config
KDE4_DIRS+=	share/kde/config.kcfg
KDE4_DIRS+=	share/kde/templates
KDE4_DIRS+=	share/kde/templates/.source
KDE4_DIRS+=	share/kde/wallpapers
KDE4_DIRS+=	share/kde4
KDE4_DIRS+=	share/kde4/services
KDE4_DIRS+=	share/kde4/services/ScreenSavers
KDE4_DIRS+=	share/kde4/services/ServiceMenus
KDE4_DIRS+=	share/kde4/services/kded
KDE4_DIRS+=	share/kde4/services/kresources
KDE4_DIRS+=	share/kde4/services/kresources/kabc
KDE4_DIRS+=	share/kde4/services/kresources/kcal
KDE4_DIRS+=	share/kde4/servicetypes

.if defined(_USE_KDE4_DIRS) && !empty(_USE_KDE4_DIRS)
DEPENDS+=	kde4-dirs>=${_USE_KDE4_DIRS}:../../misc/kde4-dirs
.endif

.endif		# !defined(DIRS_KDE4_MK)
