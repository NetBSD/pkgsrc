# $NetBSD: dirs.mk,v 1.7 2006/09/08 16:27:34 jmmv Exp $
#
# This file is intended to be included by mk/dirs.mk, not directly by packages.
#

.if !defined(DIRS_XDG_X11_MK)
DIRS_XDG_X11_MK=	# defined

XDG_X11_DIRS=		share/application-registry
XDG_X11_DIRS+=		share/applications
XDG_X11_DIRS+=		share/desktop-directories
XDG_X11_DIRS+=		share/dtds
XDG_X11_DIRS+=		share/icons
XDG_X11_DIRS+=		share/images
XDG_X11_DIRS+=		share/mime-info
XDG_X11_DIRS+=		share/pixmaps
XDG_X11_DIRS+=		share/pixmaps/backgrounds
XDG_X11_DIRS+=		share/sounds
XDG_X11_DIRS+=		share/themes

.if defined(_USE_XDG_X11_DIRS) && !empty(_USE_XDG_X11_DIRS)
DEPENDS+=		xdg-x11-dirs>=${_USE_XDG_X11_DIRS}:../../misc/xdg-x11-dirs

.  for dir in ${XDG_X11_DIRS}
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/${dir:S|/|\\/|g}$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${dir:S|/|\\/|g}$$/ \
				{ print "@comment in xdg-x11-dirs: " $$0; next; }
.  endfor
.endif

.endif			# !defined(DIRS_XDG_X11_MK)
