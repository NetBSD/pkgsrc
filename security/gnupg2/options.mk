# $NetBSD: options.mk,v 1.9 2015/03/24 08:36:56 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg2
PKG_SUPPORTED_OPTIONS=	gnupg2-gpgsm libusb
PKG_SUGGESTED_OPTIONS=	gnupg2-gpgsm

# remove after 2014Q3
PKG_OPTIONS_LEGACY_OPTS+=     gpgsm:gnupg2-gpgsm

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

## If no options are specified, only gpg-agent is built. This
## is sufficient for OpenPGP/MIME support in Kmail
## SMIME support is provided by gpgsm. This support is
## in the alpha stage of development.
PLIST_SRC=	${.CURDIR}/PLIST

# XXX It looks like that gpgsm support could be split into its own package,
# according to the configure script.  If that's true, this use of the options
# framework is incorrect and should be fixed.
.if empty(PKG_OPTIONS:Mgnupg2-gpgsm)
CONFIGURE_ARGS+=	--enable-agent-only
.else
CONFIGURE_ARGS+=	--enable-gpgsm
CONFIGURE_ARGS+=	--with-dirmngr-pgm=${BUILDLINK_PREFIX.dirmngr}/bin/dirmngr
PLIST_SRC+=	${.CURDIR}/PLIST.gpgsm
.  include "../../security/dirmngr/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibusb)
USE_TOOLS+=	pkg-config
.  include "../../devel/libusb/buildlink3.mk"
.endif
