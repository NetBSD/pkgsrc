# $NetBSD: options.mk,v 1.1 2005/02/12 22:59:28 rillig Exp $
#

### The charset option enables input/display support for various 8-bit
### codepages, chooseable at runtime.
.if !empty(PKG_OPTIONS:Mcharset)
CONFIGURE_ARGS+=	--enable-charset
PLIST_SRC+=		${PKGDIR}/PLIST.charset
.include "../../converters/libiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-charset
.endif

### The internal editor can be disabled to save disk space.
.if !empty(PKG_OPTIONS:Medit)
CONFIGURE_ARGS+=	--with-edit
PLIST_SRC+=		${PKGDIR}/PLIST.mcedit
.else
CONFIGURE_ARGS+=	--without-edit
.endif

### Enable file sizes >= 2 GB. Note that this option is considered
### experimental, as some filesize calculations are still done with
### 32 bits of precision.
.if !empty(PKG_OPTIONS:Mlargefile)
CONFIGURE_ARGS+=	--enable-largefile
.else
CONFIGURE_ARGS+=	--disable-largefile
.endif

### Enable the Samba virtual file system. You can connect to Windows
### file servers or Samba servers in your network.
.if !empty(PKG_OPTIONS:Msamba)
CONFIGURE_ARGS+=	--with-samba
.else
CONFIGURE_ARGS+=	--without-samba
.endif

### The subshell is a shell command line inside the Midnight Commander.
### It does not work well on NetBSD (does not save the screen contents).
.if !empty(PKG_OPTIONS:Msubshell)
CONFIGURE_ARGS+=	--with-subshell
.else
CONFIGURE_ARGS+=	--without-subshell
.endif

### Enable the virtual file system of the Midnight Commander. With the
### VFS you can access files via FTP, SSH, in various archive formats
### like if they were on your local disk.
.if !empty(PKG_OPTIONS:Mvfs)
CONFIGURE_ARGS+=	--with-vfs
PLIST_SRC+=		${PKGDIR}/PLIST.vfs
.else
CONFIGURE_ARGS+=	--without-vfs
.endif

### X11 support allows better key handling (detection of the Alt, Ctrl,
### Shift modifiers) and mouse support.
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
USE_X11=		yes
.else
CONFIGURE_ARGS+=	--without-x
.endif

### The Midnight Commander can use three different screen libraries to
### draw itself on the screen. SLang, ncurses, and a slim variant of
### SLang (the default), which is distributed with the Midnight Commander.
.if !empty(PKG_OPTIONS:Mslang)
CONFIGURE_ARGS+=	--with-screen=slang
.include "../../devel/libslang/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mncurses)
CONFIGURE_ARGS+=	--with-screen=ncurses
.include "../../devel/ncurses/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-screen=mcslang
.endif
