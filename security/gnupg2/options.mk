# $NetBSD: options.mk,v 1.5 2011/01/20 08:54:56 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg2
PKG_SUPPORTED_OPTIONS=	gpgsm
PKG_SUGGESTED_OPTIONS=	gpgsm

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
.if empty(PKG_OPTIONS:Mgpgsm)
CONFIGURE_ARGS+=	--enable-agent-only
.else
CONFIGURE_ARGS+=	--enable-gpgsm
CONFIGURE_ARGS+=	--with-dirmngr-pgm=${BUILDLINK_PREFIX.dirmngr}/bin/dirmngr
PLIST_SRC+=	${.CURDIR}/PLIST.gpgsm
.  include "../../security/dirmngr/buildlink3.mk"
.endif
