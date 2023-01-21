# $NetBSD: Makefile,v 1.13 2023/01/21 18:49:58 gdt Exp $

DISTNAME=	bulk-test-boost-20230121
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nia@NetBSD.org
COMMENT=	Meta-package for testing Boost

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# All of these (primarily leaf) packages depend on Boost.
# Feel free to add one if you care about it not breaking.
# The current list is mostly arbitrary, resulting from a grep of the
# pkgsrc tree.

BUILD_DEPENDS+=		abiword-[0-9]*:../../editors/abiword
BUILD_DEPENDS+=		bitcoin-[0-9]*:../../finance/bitcoin
BUILD_DEPENDS+=		blender-[0-9]*:../../graphics/blender
BUILD_DEPENDS+=		botan>=2.11:../../security/botan2
BUILD_DEPENDS+=		dnsdist-[0-9]*:../../net/dnsdist
BUILD_DEPENDS+=		emulationstation-[0-9]*:../../emulators/emulationstation
BUILD_DEPENDS+=		gnucash-[0-9]*:../../finance/gnucash
BUILD_DEPENDS+=		gnuradio-core-[0-9]*:../../ham/gnuradio-core
BUILD_DEPENDS+=		gource-[0-9]*:../../graphics/gource
BUILD_DEPENDS+=		gpick-[0-9]*:../../graphics/gpick
BUILD_DEPENDS+=		icinga2-[0-9]*:../../net/icinga2
BUILD_DEPENDS+=		inkscape-[0-9]*:../../graphics/inkscape
BUILD_DEPENDS+=		innoextract-[0-9]*:../../archivers/innoextract
BUILD_DEPENDS+=		kicad-[0-9]*:../../cad/kicad
BUILD_DEPENDS+=		krita-[0-9]*:../../graphics/krita
BUILD_DEPENDS+=		libclucene-[0-9]*:../../textproc/libclucene
BUILD_DEPENDS+=		libftdi1-[0-9]*:../../devel/libftdi1
BUILD_DEPENDS+=		librecad-[0-9]*:../../cad/librecad
BUILD_DEPENDS+=		libreoffice-[0-9]*:../../misc/libreoffice
BUILD_DEPENDS+=		mongodb-[0-9]*:../../databases/mongodb
BUILD_DEPENDS+=		mumble-[0-9]*:../../chat/mumble
BUILD_DEPENDS+=		musicpd-[0-9]*:../../audio/musicpd
BUILD_DEPENDS+=		mysql-server>=5.7<8.0:../../databases/mysql57-server
BUILD_DEPENDS+=		ncmpcpp-[0-9]*:../../audio/ncmpcpp
BUILD_DEPENDS+=		osm2pgsql-[0-9]*:../../geography/osm2pgsql
BUILD_DEPENDS+=		openscad-[0-9]*:../../cad/openscad
BUILD_DEPENDS+=		poppler-glib-[0-9]*:../../print/poppler-glib
BUILD_DEPENDS+=		powerdns-[0-9]*:../../net/powerdns
BUILD_DEPENDS+=		powerdns-recursor-[0-9]*:../../net/powerdns-recursor
BUILD_DEPENDS+=		qbittorrent-[0-9]*:../../net/qbittorrent
BUILD_DEPENDS+=		quassel-[0-9]*:../../chat/quassel
BUILD_DEPENDS+=		scribus>=1.5:../../print/scribus-qt5
BUILD_DEPENDS+=		source-highlight-[0-9]*:../../textproc/source-highlight
BUILD_DEPENDS+=		strawberry-[0-9]*:../../audio/strawberry
BUILD_DEPENDS+=		tcpflow-[0-9]*:../../net/tcpflow
BUILD_DEPENDS+=		ugrep-[0-9]*:../../textproc/ugrep
BUILD_DEPENDS+=		xsd-[0-9]*:../../devel/xsd
BUILD_DEPENDS+=		znc-[0-9]*:../../chat/znc

.include "../../mk/bsd.pkg.mk"
