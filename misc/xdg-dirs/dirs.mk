# $NetBSD: dirs.mk,v 1.7 2006/09/08 16:27:34 jmmv Exp $
#
# This file is intended to be included by mk/dirs.mk, not directly by packages.
#

.if !defined(DIRS_XDG_MK)
DIRS_XDG_MK=		# defined

XDG_DIRS=		share/application-registry
XDG_DIRS+=		share/applications
XDG_DIRS+=		share/desktop-directories
XDG_DIRS+=		share/dtds
XDG_DIRS+=		share/icons
XDG_DIRS+=		share/images
XDG_DIRS+=		share/mime-info
XDG_DIRS+=		share/pixmaps
XDG_DIRS+=		share/pixmaps/backgrounds
XDG_DIRS+=		share/sounds
XDG_DIRS+=		share/themes

.if defined(_USE_XDG_DIRS) && !empty(_USE_XDG_DIRS)
DEPENDS+=		xdg-dirs>=${_USE_XDG_DIRS}:../../misc/xdg-dirs

.  for dir in ${XDG_DIRS}
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/${dir:S|/|\\/|g}$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${dir:S|/|\\/|g}$$/ \
				{ print "@comment in xdg-dirs: " $$0; next; }
.  endfor
.endif

.endif			# !defined(DIRS_XDG_MK)
