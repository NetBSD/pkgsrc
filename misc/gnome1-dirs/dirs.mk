# $NetBSD: dirs.mk,v 1.5 2009/06/14 22:58:04 joerg Exp $
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
.endif

.endif			# !defined(DIRS_GNOME1_MK)
