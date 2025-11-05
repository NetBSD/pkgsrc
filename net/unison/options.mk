# $NetBSD: options.mk,v 1.10 2025/11/05 00:21:39 gdt Exp $

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
PLIST.gtk3=	yes

DEPENDS+=	font-schumacher-misc>=1.0:../../fonts/font-schumacher-misc
.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minotify)
PLIST.monitor=	yes

.include "../../devel/libinotify/buildlink3.mk"
.endif
