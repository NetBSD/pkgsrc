# $NetBSD: dirs.mk,v 1.2 2004/05/15 13:35:51 jmmv Exp $
#
# This file is intended to be included by misc/gnome1/dirs.mk and
# misc/gnome2/dirs.mk, not directly by packages.
#

.if !defined(DIRS_GNOME_MK)
DIRS_GNOME_MK=		# defined

GNOME_DIRS=		share/gnome
GNOME_DIRS+=		share/gnome/apps
GNOME_DIRS+=		share/gnome/apps/Applications
GNOME_DIRS+=		share/gnome/apps/Development
GNOME_DIRS+=		share/gnome/apps/Games
GNOME_DIRS+=		share/gnome/apps/Graphics
GNOME_DIRS+=		share/gnome/apps/Internet
GNOME_DIRS+=		share/gnome/apps/Multimedia
GNOME_DIRS+=		share/gnome/apps/Settings
GNOME_DIRS+=		share/gnome/apps/Settings/Desktop
GNOME_DIRS+=		share/gnome/apps/Settings/Peripherals
GNOME_DIRS+=		share/gnome/apps/Settings/Session
GNOME_DIRS+=		share/gnome/apps/System
GNOME_DIRS+=		share/gnome/apps/Utilities
GNOME_DIRS+=		share/gnome/help
GNOME_DIRS+=		share/gnome/help/fdl
GNOME_DIRS+=		share/gnome/help/fdl/C
GNOME_DIRS+=		share/gnome/help/fdl/C/figures
GNOME_DIRS+=		share/gnome/help/gpl
GNOME_DIRS+=		share/gnome/help/gpl/C
GNOME_DIRS+=		share/gnome/help/gpl/C/figures
GNOME_DIRS+=		share/gnome/help/lgpl
GNOME_DIRS+=		share/gnome/help/lgpl/C
GNOME_DIRS+=		share/gnome/help/lgpl/C/figures

.endif			# !defined(DIRS_GNOME_MK)
