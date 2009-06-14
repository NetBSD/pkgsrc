# $NetBSD: dirs.mk,v 1.8 2009/06/14 22:58:05 joerg Exp $
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
.endif

.endif			# !defined(DIRS_XDG_MK)
