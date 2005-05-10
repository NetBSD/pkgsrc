# $NetBSD: dirs.mk,v 1.2 2005/05/10 20:21:57 jmmv Exp $
#
# This file is intended to be included by mk/dirs.mk, not directly by packages.
#

.if !defined(DIRS_THEME_MK)
DIRS_THEME_MK=		# defined

THEME_DIRS=		share/themes/AgingGorilla
THEME_DIRS+=		share/themes/Atlanta
THEME_DIRS+=		share/themes/Bright
THEME_DIRS+=		share/themes/Clearlooks
THEME_DIRS+=		share/themes/Crux
THEME_DIRS+=		share/themes/Esco
THEME_DIRS+=		share/themes/Glider
THEME_DIRS+=		share/themes/Grand-Canyon
THEME_DIRS+=		share/themes/HighContrast
THEME_DIRS+=		share/themes/HighContrastInverse
THEME_DIRS+=		share/themes/HighContrastLargePrint
THEME_DIRS+=		share/themes/HighContrastLargePrintInverse
THEME_DIRS+=		share/themes/Industrial
THEME_DIRS+=		share/themes/LargePrint
THEME_DIRS+=		share/themes/LighthouseBlue
THEME_DIRS+=		share/themes/LowContrast
THEME_DIRS+=		share/themes/LowContrastLargePrint
THEME_DIRS+=		share/themes/Metabox
THEME_DIRS+=		share/themes/Metal
THEME_DIRS+=		share/themes/Mist
THEME_DIRS+=		share/themes/Ocean-Dream
THEME_DIRS+=		share/themes/Redmond
THEME_DIRS+=		share/themes/Sandwish
THEME_DIRS+=		share/themes/Simple
THEME_DIRS+=		share/themes/Smokey
THEME_DIRS+=		share/themes/Smokey-Blue
THEME_DIRS+=		share/themes/ThinIce
THEME_DIRS+=		share/themes/Traditional

.if defined(_USE_THEME_DIRS) && !empty(_USE_THEME_DIRS)
DEPENDS+=		theme-dirs>=${_USE_THEME_DIRS}:../../misc/theme-dirs

.  for dir in ${THEME_DIRS}
PRINT_PLIST_AWK+=	/^@dirrm ${dir:S|/|\\/|g}$$/ \
				{ print "@comment in theme-dirs: " $$0; next; }
.  endfor
.  undef dir
.endif

.endif			# !defined(DIRS_THEME_MK)
