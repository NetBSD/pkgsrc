# $NetBSD: Makefile,v 1.18 2024/05/08 13:07:41 gdt Exp $

DISTNAME=	bulk-test-boost-20231230
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
DEPENDS+=	musicpd-[0-9]*:../../audio/musicpd
DEPENDS+=	ncmpcpp-[0-9]*:../../audio/ncmpcpp
DEPENDS+=	osm2pgsql-[0-9]*:../../geography/osm2pgsql
DEPENDS+=	openscad-[0-9]*:../../cad/openscad
DEPENDS+=	poppler-[0-9]*:../../print/poppler
DEPENDS+=	powerdns-[0-9]*:../../net/powerdns
DEPENDS+=	powerdns-recursor-[0-9]*:../../net/powerdns-recursor
DEPENDS+=	qbittorrent-[0-9]*:../../net/qbittorrent
DEPENDS+=	quassel-[0-9]*:../../chat/quassel
DEPENDS+=	scribus>=1.5:../../print/scribus-qt5
DEPENDS+=	source-highlight-[0-9]*:../../textproc/source-highlight
DEPENDS+=	strawberry-[0-9]*:../../audio/strawberry
DEPENDS+=	tcpflow-[0-9]*:../../net/tcpflow
DEPENDS+=	ugrep-[0-9]*:../../textproc/ugrep
DEPENDS+=	xsd-[0-9]*:../../devel/xsd
DEPENDS+=	znc-[0-9]*:../../chat/znc

.include "../../mk/bsd.pkg.mk"
