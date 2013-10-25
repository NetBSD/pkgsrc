# $NetBSD: options.mk,v 1.13 2013/10/25 06:53:33 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.mc
PKG_OPTIONS_REQUIRED_GROUPS=	screen
PKG_OPTIONS_GROUP.screen=	ncurses slang
PKG_SUPPORTED_OPTIONS=	mc-charset mc-edit mc-samba mc-subshell mc-vfs x11
PKG_SUGGESTED_OPTIONS=	mc-charset mc-edit mc-subshell mc-vfs slang

.include "../../mk/bsd.options.mk"

### The charset option enables input/display support for various 8-bit
### codepages, chooseable at runtime.
.if !empty(PKG_OPTIONS:Mmc-charset)
CONFIGURE_ARGS+=	--enable-charset
PLIST_SRC+=		${PKGDIR}/PLIST.charset
.include "../../converters/libiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-charset
.endif

### The internal editor can be disabled to save disk space.
.if !empty(PKG_OPTIONS:Mmc-edit)
CONFIGURE_ARGS+=	--with-edit
PLIST_SRC+=		${PKGDIR}/PLIST.mcedit
.else
CONFIGURE_ARGS+=	--without-edit
.endif

### Enable the Samba virtual file system. You can connect to Windows
### file servers or Samba servers in your network.
.if !empty(PKG_OPTIONS:Mmc-samba)
CONFIGURE_ARGS+=	--with-samba
.else
CONFIGURE_ARGS+=	--without-samba
.endif

### The subshell is a shell command line inside the Midnight Commander.
.if !empty(PKG_OPTIONS:Mmc-subshell)
CONFIGURE_ARGS+=	--with-subshell
.else
CONFIGURE_ARGS+=	--without-subshell
.endif

### Enable the virtual file system of the Midnight Commander. With the
### VFS you can access files via FTP, SSH, in various archive formats
### like if they were on your local disk.
.if !empty(PKG_OPTIONS:Mmc-vfs)
PLIST_SRC+=		${PKGDIR}/PLIST.vfs
USE_TOOLS+=		perl:run
.else
CONFIGURE_ARGS+=	--disable-vfs
.endif

### X11 support allows better key handling (detection of the Alt, Ctrl,
### Shift modifiers) and mouse support.
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=		--with-x
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--without-x
.endif

### The Midnight Commander can use three different screen libraries to
### draw itself on the screen. SLang, ncurses, and a slim variant of
### SLang (the default), which is distributed with the Midnight Commander.
.if !empty(PKG_OPTIONS:Mslang)
CONFIGURE_ARGS+=	--with-screen=slang
.include "../../devel/libslang2/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mncurses)
USE_NCURSES=		yes
CONFIGURE_ARGS+=	--with-screen=ncurses
.include "../../devel/ncurses/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-screen=mcslang
.endif
