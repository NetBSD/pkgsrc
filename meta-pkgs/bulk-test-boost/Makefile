# $NetBSD: Makefile,v 1.14 2023/06/06 12:41:54 riastradh Exp $

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

TOOL_DEPENDS+=		abiword-[0-9]*:../../editors/abiword
TOOL_DEPENDS+=		bitcoin-[0-9]*:../../finance/bitcoin
TOOL_DEPENDS+=		blender-[0-9]*:../../graphics/blender
TOOL_DEPENDS+=		botan>=2.11:../../security/botan2
TOOL_DEPENDS+=		dnsdist-[0-9]*:../../net/dnsdist
TOOL_DEPENDS+=		emulationstation-[0-9]*:../../emulators/emulationstation
TOOL_DEPENDS+=		gnucash-[0-9]*:../../finance/gnucash
TOOL_DEPENDS+=		gnuradio-core-[0-9]*:../../ham/gnuradio-core
TOOL_DEPENDS+=		gource-[0-9]*:../../graphics/gource
TOOL_DEPENDS+=		gpick-[0-9]*:../../graphics/gpick
TOOL_DEPENDS+=		icinga2-[0-9]*:../../net/icinga2
TOOL_DEPENDS+=		inkscape-[0-9]*:../../graphics/inkscape
TOOL_DEPENDS+=		innoextract-[0-9]*:../../archivers/innoextract
TOOL_DEPENDS+=		kicad-[0-9]*:../../cad/kicad
TOOL_DEPENDS+=		krita-[0-9]*:../../graphics/krita
TOOL_DEPENDS+=		libclucene-[0-9]*:../../textproc/libclucene
TOOL_DEPENDS+=		libftdi1-[0-9]*:../../devel/libftdi1
TOOL_DEPENDS+=		librecad-[0-9]*:../../cad/librecad
TOOL_DEPENDS+=		libreoffice-[0-9]*:../../misc/libreoffice
TOOL_DEPENDS+=		mongodb-[0-9]*:../../databases/mongodb
TOOL_DEPENDS+=		mumble-[0-9]*:../../chat/mumble
TOOL_DEPENDS+=		musicpd-[0-9]*:../../audio/musicpd
TOOL_DEPENDS+=		mysql-server>=5.7<8.0:../../databases/mysql57-server
TOOL_DEPENDS+=		ncmpcpp-[0-9]*:../../audio/ncmpcpp
TOOL_DEPENDS+=		osm2pgsql-[0-9]*:../../geography/osm2pgsql
TOOL_DEPENDS+=		openscad-[0-9]*:../../cad/openscad
TOOL_DEPENDS+=		poppler-glib-[0-9]*:../../print/poppler-glib
TOOL_DEPENDS+=		powerdns-[0-9]*:../../net/powerdns
TOOL_DEPENDS+=		powerdns-recursor-[0-9]*:../../net/powerdns-recursor
TOOL_DEPENDS+=		qbittorrent-[0-9]*:../../net/qbittorrent
TOOL_DEPENDS+=		quassel-[0-9]*:../../chat/quassel
TOOL_DEPENDS+=		scribus>=1.5:../../print/scribus-qt5
TOOL_DEPENDS+=		source-highlight-[0-9]*:../../textproc/source-highlight
TOOL_DEPENDS+=		strawberry-[0-9]*:../../audio/strawberry
TOOL_DEPENDS+=		tcpflow-[0-9]*:../../net/tcpflow
TOOL_DEPENDS+=		ugrep-[0-9]*:../../textproc/ugrep
TOOL_DEPENDS+=		xsd-[0-9]*:../../devel/xsd
TOOL_DEPENDS+=		znc-[0-9]*:../../chat/znc

.include "../../mk/bsd.pkg.mk"
