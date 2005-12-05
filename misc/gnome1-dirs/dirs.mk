# $NetBSD: dirs.mk,v 1.4 2005/12/05 20:50:39 rillig Exp $
#
# This file is intended to be included by mk/dirs.mk, not directly by packages.
#

.if !defined(DIRS_GNOME1_MK)
DIRS_GNOME1_MK=		# defined

_USE_XDG_X11_DIRS=	1.1
.include "../../misc/xdg-x11-dirs/dirs.mk"
.include "../../misc/gnome-dirs/dirs.mk"

GNOME1_DIRS=		# none yet

.if defined(_USE_GNOME1_DIRS) && !empty(_USE_GNOME1_DIRS)
DEPENDS+=		gnome1-dirs>=${_USE_GNOME1_DIRS}:../../misc/gnome1-dirs

.  for dir in ${GNOME_DIRS} ${GNOME1_DIRS}
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/${dir:S|/|\\/|g}$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${dir:S|/|\\/|g}$$/ \
				{ print "@comment in gnome1-dirs: " $$0; next; }
.  endfor
.endif

.endif			# !defined(DIRS_GNOME1_MK)
