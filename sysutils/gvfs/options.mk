# $NetBSD: options.mk,v 1.7 2026/05/10 17:38:14 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gvfs
PKG_SUPPORTED_OPTIONS=	bluray cdda dnssd fuse goa gcr gphoto idevice libgdata \
			libmtp polkit samba secret udev
PKG_SUGGESTED_OPTIONS=	gcr dnssd secret

.if ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	samba
.endif

.if ${OPSYS} == "Linux" || (${OPSYS} == "NetBSD" && ${OPSYS_VERSION} > 099993)
PKG_SUGGESTED_OPTIONS+=	fuse
.endif

# Check for a working udev implementation.
# If available, enable some options which depend on it.
.include "../../mk/udev.buildlink3.mk"
.if ${UDEV_TYPE} != "none"
PKG_SUGGESTED_OPTIONS+=	udev
PKG_SUGGESTED_OPTIONS+=	cdda libmtp
.endif

.if ${OPSYS} == "Linux"
# polkit itself is cross-platform but gvfs also requires libcap, which is
# only available on Linux.
PKG_SUGGESTED_OPTIONS+=	polkit
.endif

.include "../../mk/bsd.options.mk"

# Some options expect gudev support:
# use the GUDEV_REQUIRED variable to handle them.
GUDEV_REQUIRED?=	# empty

# Gnome Online Accounts support:
# some users might have a reason not to want it by default.
GOA_REQUIRED?=		# empty

###
### afc://{UUID}
###  Apple File Conduit; allow to exchange files with iOS devices
###
PLIST_VARS+=	afc
.if !empty(PKG_OPTIONS:Midevice)
MESON_ARGS+=    -Dafc=true
PLIST.afc=	yes
.  include "../../comms/libimobiledevice/buildlink3.mk"
.  include "../../textproc/libplist/buildlink3.mk"
.else
MESON_ARGS+=	-Dafc=false
.endif

###
### admin:///
###   Access local filesystem as a root user.
###
PLIST_VARS+=	polkit
.if !empty(PKG_OPTIONS:Mpolkit)
MESON_ARGS+=	-Dadmin=true
PLIST.polkit=	yes
.  include "../../sysutils/libcap/buildlink3.mk"
.  include "../../security/polkit/buildlink3.mk"
.else
MESON_ARGS+=	-Dadmin=false
.endif

###
#### Blu-Ray metadata support.
###
.if !empty(PKG_OPTIONS:Mbluray)
MESON_ARGS+=    -Dbluray=true
.  include "../../multimedia/libbluray/buildlink3.mk"
.else
MESON_ARGS+=    -Dbluray=false
.endif

###
###  cdda://{DEVICE}
###    Access audio discs.
###
PLIST_VARS+=    cdda
.if !empty(PKG_OPTIONS:Mcdda)
MESON_ARGS+=    -Dcdda=true
GUDEV_REQUIRED= yes
.  include "../../misc/libcdio-paranoia/buildlink3.mk"
PLIST.cdda=     yes
.else
MESON_ARGS+=    -Dcdda=false
.endif

###
### dns-sd://{DOMAIN}
###   DNS-SD shares on the local network.
###
PLIST_VARS+=	dnssd
.if !empty(PKG_OPTIONS:Mdnssd)
MESON_ARGS+=	-Ddnssd=true
PLIST.dnssd=	yes
.  include "../../net/avahi/buildlink3.mk"
.else
MESON_ARGS+=	-Ddnssd=false
.endif

###
### FUSE support.
###
### NOTE: gvfsd-fuse is known not to work on NetBSD
### This is because NetBSD refuse(3) doesn't support non-root mounting but
### gvfsd(1) relies on this specific functionality. gvfsd(1) launches
### gvfsd-fuse(1) as a regular user, and it exits with an error. We should
### really implement fusermount(1) as a part of refuse(3).
###
PLIST_VARS+=	fuse
.if !empty(PKG_OPTIONS:Mfuse)
USE_FUSE3=	yes
.include "../../mk/fuse.buildlink3.mk"
MESON_ARGS+=	-Dfuse=true
PLIST.fuse=             yes
.else
MESON_ARGS+=	-Dfuse=false
.endif

###
### GCR certificate support.
###
.if !empty(PKG_OPTIONS:Mgcr)
MESON_ARGS+=    -Dgcr=true
.  include "../../security/gcr4/buildlink3.mk"
.else
MESON_ARGS+=    -Dgcr=false
.endif

###
### google-drive://{USER}@{HOST}
###   Access Google Drive.
###
PLIST_VARS+=	gdata
.if !empty(PKG_OPTIONS:Mlibgdata)
GOA_REQUIRED=	yes
MESON_ARGS+=	-Dgoogle=true
PLIST.gdata=	yes
.  include "../../net/libgdata/buildlink3.mk"
.else
MESON_ARGS+=	-Dgoogle=false
.endif

###
### GOA (Gnome Online Accounts).
### Required for Google Drive support.
###
.if !empty(PKG_OPTIONS:Mgoa) || ${GOA_REQUIRED:tl} == "yes"
MESON_ARGS+=    -Dgoa=true
.  include "../../net/gnome-online-accounts/buildlink3.mk"
.else
MESON_ARGS+=    -Dgoa=false
.endif

###
### gphoto2://{ID_SERIAL}, gphoto2://[usb:bus,dev]
###   Access digital cameras.
###
PLIST_VARS+=    gphoto
.if !empty(PKG_OPTIONS:Mgphoto)
MESON_ARGS+=    -Dgphoto2=true
GUDEV_REQUIRED= yes
PLIST.gphoto=  yes
.  include "../../devel/libgphoto2/buildlink3.mk"
.else
MESON_ARGS+=    -Dgphoto2=false
.endif

###
### mtp://{ID_SERIAL}, mtp://[usb:bus,dev]
###   Access digital audio/media players.
###
PLIST_VARS+=    mtp
.if !empty(PKG_OPTIONS:Mlibmtp)
GUDEV_REQUIRED=	yes
MESON_ARGS+=	-Dmtp=true
.  include "../../devel/libmtp/buildlink3.mk"
PLIST.mtp=	yes
.else
MESON_ARGS+=    -Dmtp=false
.endif

###
### smb://[user@]host[:port][/share]
###   SMB/CIFS protocol support.
###
PLIST_VARS+=	smb
.if !empty(PKG_OPTIONS:Msamba)
MESON_ARGS+=	-Dsmb=true
PLIST.smb=	yes
.  include "../../net/samba4/buildlink3.mk"
.else
MESON_ARGS+=	-Dsmb=false
.endif

###
### GNOME Keyring support.
###
.if !empty(PKG_OPTIONS:Msecret)
MESON_ARGS+=	-Dkeyring=true
.  include "../../security/libsecret/buildlink3.mk"
.else
MESON_ARGS+=	-Dkeyring=false
.endif

###
### GUdev device support.
###
.if !empty(PKG_OPTIONS:Mudev) || ${GUDEV_REQUIRED:tl} == "yes"
MESON_ARGS+=    -Dgudev=true
.  include "../../devel/libgudev/buildlink3.mk"
.else
MESON_ARGS+=    -Dgudev=false
.endif
