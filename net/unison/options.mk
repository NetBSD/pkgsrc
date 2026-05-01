# $NetBSD: options.mk,v 1.12 2026/05/01 00:40:59 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unison
PKG_SUPPORTED_OPTIONS=	lablgtk inotify
PKG_SUGGESTED_OPTIONS=	lablgtk

# gtk3 is true if unison-gui is built.
# monitor is true if unison-fsmonitor is built.
PLIST_VARS+=	gtk3 monitor

# Extend to systems as they are tested to build fsmonitor.
# \todo FreeBSD, Linux, macOS, OpenBSD, SunOS.
# \todo Perhaps, just enable unless libinotify says NOT_FOR_PLATFORM.

.if ${MACHINE_PLATFORM:MNetBSD-*}
PKG_SUGGESTED_OPTIONS+=	inotify
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlablgtk)
BUILD_TARGET+=	gui

PLIST.gtk3=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

DEPENDS+=	font-schumacher-misc>=1.0:../../fonts/font-schumacher-misc
.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minotify)
BUILD_TARGET+=	fsmonitor

PLIST.monitor=	yes

.include "../../devel/libinotify/buildlink3.mk"
.endif
