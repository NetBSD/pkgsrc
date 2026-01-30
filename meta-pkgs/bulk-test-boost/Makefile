# $NetBSD: Makefile,v 1.23 2026/01/30 08:58:48 wiz Exp $

DISTNAME=	bulk-test-boost-20260130
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nia@NetBSD.org
COMMENT=	Meta-package for testing Boost

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# This package intends to depend on all packages that depend on boost,
# so that it can be used to qualify updates.
#
# Feel free to add packages.  To find packages that depend on
# boost-headers:
#   revbump.py -n devel/boost-headers
# The current list is a small subset of the 279 in pkgsrc, for no
# particular reason,

DEPENDS+=	abiword-[0-9]*:../../editors/abiword
DEPENDS+=	bitcoin-[0-9]*:../../finance/bitcoin
DEPENDS+=	blender-[0-9]*:../../graphics/blender
DEPENDS+=	botan>=2.11:../../security/botan2
DEPENDS+=	dnsdist-[0-9]*:../../net/dnsdist
DEPENDS+=	emulationstation-[0-9]*:../../emulators/emulationstation
DEPENDS+=	gnucash-[0-9]*:../../finance/gnucash
DEPENDS+=	gnuradio-core-[0-9]*:../../ham/gnuradio-core
DEPENDS+=	gource-[0-9]*:../../graphics/gource
DEPENDS+=	gpick-[0-9]*:../../graphics/gpick
DEPENDS+=	gr-osmosdr-[0-9]*:../../ham/gr-osmosdr
DEPENDS+=	hugin-[0-9]*:../../graphics/hugin
DEPENDS+=	icinga2-[0-9]*:../../net/icinga2
DEPENDS+=	inkscape-[0-9]*:../../graphics/inkscape
DEPENDS+=	innoextract-[0-9]*:../../archivers/innoextract
DEPENDS+=	kicad-[0-9]*:../../cad/kicad
DEPENDS+=	krita-[0-9]*:../../graphics/krita
DEPENDS+=	libclucene-[0-9]*:../../textproc/libclucene
DEPENDS+=	libftdi1-[0-9]*:../../devel/libftdi1
DEPENDS+=	librecad-[0-9]*:../../cad/librecad
DEPENDS+=	libreoffice-[0-9]*:../../misc/libreoffice
DEPENDS+=	mongodb-3*:../../databases/mongodb3
DEPENDS+=	mongodb-[0-9]*:../../databases/mongodb
DEPENDS+=	mumble-[0-9]*:../../chat/mumble
DEPENDS+=	ncmpcpp-[0-9]*:../../audio/ncmpcpp
DEPENDS+=	openscad-[0-9]*:../../cad/openscad
DEPENDS+=	osm2pgsql-[0-9]*:../../geography/osm2pgsql
DEPENDS+=	poppler-[0-9]*:../../print/poppler
DEPENDS+=	powerdns-[0-9]*:../../net/powerdns
DEPENDS+=	powerdns-recursor-[0-9]*:../../net/powerdns-recursor
DEPENDS+=	qbittorrent-[0-9]*:../../net/qbittorrent
DEPENDS+=	quassel-[0-9]*:../../chat/quassel
DEPENDS+=	scribus>=1.5:../../print/scribus
DEPENDS+=	source-highlight-[0-9]*:../../textproc/source-highlight
DEPENDS+=	strawberry-[0-9]*:../../audio/strawberry
DEPENDS+=	supertux-[0-9]*:../../games/supertux
DEPENDS+=	tcpflow-[0-9]*:../../net/tcpflow
DEPENDS+=	ugrep-[0-9]*:../../textproc/ugrep
DEPENDS+=	uhd-[0-9]*:../../ham/uhd
DEPENDS+=	vcmi-[0-9]*:../../games/vcmi
DEPENDS+=	wesnoth-[0-9]*:../../games/wesnoth
DEPENDS+=	xsd-[0-9]*:../../devel/xsd
DEPENDS+=	znc-[0-9]*:../../chat/znc

.include "../../mk/bsd.pkg.mk"
