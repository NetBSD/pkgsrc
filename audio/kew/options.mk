# $NetBSD: options.mk,v 1.5 2026/07/30 18:20:55 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kew
PKG_SUPPORTED_OPTIONS=	dbus artist-db
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
###  Include dbus
###
.if !empty(PKG_OPTIONS:Mdbus)
MAKE_FLAGS+=	USE_DBUS=1
.include "../../sysutils/dbus/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_DBUS=0
.endif

###
###  Include artist database for clickable artist names
###
PLIST_VARS+=	artists
.if !empty(PKG_OPTIONS:Martist-db)
VERSION_HASH=	8f0c30b1b4ee593117b41bbc6074a895d6a61639

ARTIST_DB=	artists-${VERSION_HASH:C%^(.......).*%\1%}.db
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	${ARTIST_DB}

PLIST.artists=		yes

SITES.${ARTIST_DB}= \
	-https://github.com/ravachol/kew-data/raw/${VERSION_HASH}/artists.db

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

post-install:
	${INSTALL_DATA} ${WRKDIR}/${ARTIST_DB} ${DESTDIR}${PREFIX}/share/kew/artists.db

.endif
