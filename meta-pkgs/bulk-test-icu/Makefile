# $NetBSD: Makefile,v 1.4 2024/10/11 08:14:26 jperkin Exp $

DISTNAME=	bulk-test-icu-20240815
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package for testing ICU

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# All of these (primarily leaf) packages depend on ICU.
# Feel free to add one if you care about it not breaking.
# The current list is mostly arbitrary, resulting from a grep of the
# pkgsrc tree.

DEPENDS+=	musicpd-[0-9]*:../../audio/musicpd
DEPENDS+=	ncmpcpp-[0-9]*:../../audio/ncmpcpp
DEPENDS+=	strawberry-[0-9]*:../../audio/strawberry
DEPENDS+=	dino-[0-9]*:../../chat/dino
DEPENDS+=	prosody-[0-9]*:../../chat/prosody
DEPENDS+=	znc-[0-9]*:../../chat/znc
DEPENDS+=	libcdr-[0-9]*:../../converters/libcdr
DEPENDS+=	libe-book-[0-9]*:../../converters/libe-book
DEPENDS+=	libfreehand-[0-9]*:../../converters/libfreehand
DEPENDS+=	libmspub-[0-9]*:../../converters/libmspub
DEPENDS+=	libqxp-[0-9]*:../../converters/libqxp
DEPENDS+=	libvisio-[0-9]*:../../converters/libvisio
DEPENDS+=	libzmf-[0-9]*:../../converters/libzmf
DEPENDS+=	couchdb-[0-9]*:../../databases/couchdb
DEPENDS+=	mongo-c-driver-[0-9]*:../../databases/mongo-c-driver
# Testing mongodb3
#DEPENDS+=	mongodb-[0-9]*:../../databases/mongodb
DEPENDS+=	mongodb-[0-9]*:../../databases/mongodb3
#DEPENDS+=	mongodb-[0-9]*:../../databases/mongodb4
DEPENDS+=	mysql-client-[0-9]*:../../databases/mysql80-client
# protobuf problem. internel protobuf has rpath problem.
#DEPENDS+=	mysql-server-[0-9]*:../../databases/mysql80-server
DEPENDS+=	sqlite3-[0-9]*:../../databases/sqlite3
DEPENDS+=	boost-libs-[0-9]*:../../devel/boost-libs
DEPENDS+=	gnustep-base-[0-9]*:../../devel/gnustep-base
DEPENDS+=	poedit-[0-9]*:../../editors/poedit
DEPENDS+=	fuse-darling-dmg-[0-9]*:../../filesystems/fuse-darling-dmg
DEPENDS+=	ltfs-ltotape-[0-9]*:../../filesystems/ltfs-ltotape
DEPENDS+=	ltfs-[0-9]*:../../filesystems/ltfs
DEPENDS+=	gnucash-[0-9]*:../../finance/gnucash
DEPENDS+=	harfbuzz-icu-[0-9]*:../../fonts/harfbuzz-icu
# fmtlib problem. marked as broken
#DEPENDS+=	0ad-[0-9]*:../../games/0ad
DEPENDS+=	liblcf-[0-9]*:../../games/liblcf
DEPENDS+=	openrct2-[0-9]*:../../games/openrct2
DEPENDS+=	openttd-[0-9]*:../../games/openttd
DEPENDS+=	wesnoth-[0-9]*:../../games/wesnoth
DEPENDS+=	widelands-[0-9]*:../../games/widelands
DEPENDS+=	darktable-[0-9]*:../../graphics/darktable
DEPENDS+=	imv-[0-9]*:../../graphics/imv
DEPENDS+=	tesseract-[0-9]*:../../graphics/tesseract
DEPENDS+=	vtk-[0-9]*:../../graphics/vtk
DEPENDS+=	gnuradio-core-[0-9]*:../../ham/gnuradio-core
DEPENDS+=	ibus-qt-[0-9]*:../../inputmethod/ibus-qt
DEPENDS+=	mono-[0-9]*:../../lang/mono
DEPENDS+=	mozjs78-[0-9]*:../../lang/mozjs78
# Testing the latest node.js
DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs
#DEPENDS+=	nodejs18-[0-9]*:../../lang/nodejs18
#DEPENDS+=	nodejs20-[0-9]*:../../lang/nodejs20
DEPENDS+=	parrot-[0-9]*:../../lang/parrot
DEPENDS+=	dovecot-fts-flatcurve-[0-9]*:../../mail/dovecot2-fts-flatcurve
DEPENDS+=	evolution-data-server-[0-9]*:../../mail/evolution-data-server
DEPENDS+=	rspamd-[0-9]*:../../mail/rspamd
DEPENDS+=	thunderbird102-[0-9]*:../../mail/thunderbird102
# Rust problem
#DEPENDS+=	thunderbird68-[0-9]*:../../mail/thunderbird68
# Python problem
#DEPENDS+=	thunderbird78-[0-9]*:../../mail/thunderbird78
DEPENDS+=	qalculate-[0-9]*:../../math/qalculate
DEPENDS+=	calibre-[0-9]*:../../misc/calibre
DEPENDS+=	libreoffice-[0-9]*:../../misc/libreoffice
DEPENDS+=	sword-[0-9]*:../../misc/sword
DEPENDS+=	yaz-[0-9]*:../../net/yaz
DEPENDS+=	tin-[0-9]*:../../news/tin
DEPENDS+=	bibtexu-[0-9]*:../../print/bibtexu
# unknown build failure
#DEPENDS+=	scribus-qt5-[0-9]*:../../print/scribus-qt5
DEPENDS+=	sile-[0-9]*:../../print/sile
DEPENDS+=	xetex-[0-9]*:../../print/xetex
DEPENDS+=	gnome-tracker-[0-9]*:../../sysutils/gnome-tracker
DEPENDS+=	open-vm-tools-[0-9]*:../../sysutils/open-vm-tools
DEPENDS+=	R-stringi-[0-9]*:../../textproc/R-stringi
DEPENDS+=	dwdiff-[0-9]*:../../textproc/dwdiff
DEPENDS+=	hfstospell-[0-9]*:../../textproc/hfstospell
DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
DEPENDS+=	nuspell-[0-9]*:../../textproc/nuspell
DEPENDS+=	${PHP_PKG_PREFIX}-intl-[0-9]*:../../textproc/php-intl
DEPENDS+=	${PYPKGPREFIX}-ICU-[0-9]*:../../textproc/py-ICU
DEPENDS+=	split-thai-[0-9]*:../../textproc/split-thai
DEPENDS+=	upmendex-[0-9]*:../../textproc/upmendex
DEPENDS+=	libical-[0-9]*:../../time/libical
DEPENDS+=	arcticfox-[0-9]*:../../www/arcticfox
DEPENDS+=	cppcms-[0-9]*:../../www/cppcms
DEPENDS+=	firefox-[0-9]*:../../www/firefox
DEPENDS+=	firefox115-[0-9]*:../../www/firefox115
# Not built for recent environments
#DEPENDS+=	firefox52-[0-9]*:../../www/firefox52
# Only for PHP 7
#DEPENDS+=	${PHP_PKG_PREFIX}-http3-[0-9]*:../../www/php-http3
DEPENDS+=	${PHP_PKG_PREFIX}-http-[0-9]*:../../www/php-http4
DEPENDS+=	seamonkey-[0-9]*:../../www/seamonkey
DEPENDS+=	webkit-gtk-[0-9]*:../../www/webkit-gtk
DEPENDS+=	maim-[0-9]*:../../x11/maim
DEPENDS+=	qt5-qtbase-[0-9]*:../../x11/qt5-qtbase
DEPENDS+=	qt5-qtwebengine-[0-9]*:../../x11/qt5-qtwebengine
DEPENDS+=	qt5-qtwebkit-[0-9]*:../../x11/qt5-qtwebkit
DEPENDS+=	qt6-qtbase-[0-9]*:../../x11/qt6-qtbase
DEPENDS+=	slop-[0-9]*:../../x11/slop
DEPENDS+=	vte3-[0-9]*:../../x11/vte3

.include "../../lang/python/pyversion.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
