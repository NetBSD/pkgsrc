# $NetBSD: Makefile,v 1.1 2026/05/17 09:13:10 wiz Exp $

DISTNAME=	bulk-test-doxygen-20260517
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package for testing doxygen

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# This package intends to depend on all packages that depend on doxygen,
# so that it can be used to qualify updates.
#
# When using this to test an update, globally turn on the 'doxygen'
# option.

DEPENDS+=	libfishsound-[0-9]*:../../audio/libfishsound
DEPENDS+=	libopus-[0-9]*:../../audio/libopus
DEPENDS+=	lilv-[0-9]*:../../audio/lilv
DEPENDS+=	lv2-[0-9]*:../../audio/lv2
DEPENDS+=	openobex-[0-9]*:../../comms/openobex
DEPENDS+=	sratom-[0-9]*:../../converters/sratom
DEPENDS+=	avr-libc-[0-9]*:../../cross/avr-libc
DEPENDS+=	freetds-[0-9]*:../../databases/freetds
DEPENDS+=	libpqxx-[0-9]*:../../databases/libpqxx
DEPENDS+=	RE-flex-[0-9]*:../../devel/RE-flex
DEPENDS+=	cppunit-[0-9]*:../../devel/cppunit
DEPENDS+=	editorconfig-core-[0-9]*:../../devel/editorconfig-core
DEPENDS+=	libnet-[0-9]*:../../devel/libnet
DEPENDS+=	libnfc-[0-9]*:../../devel/libnfc
DEPENDS+=	zix-[0-9]*:../../devel/zix
DEPENDS+=	simulavr-[0-9]*:../../emulators/simulavr
DEPENDS+=	naev-[0-9]*:../../games/naev
DEPENDS+=	libpgf-[0-9]*:../../graphics/libpgf
DEPENDS+=	vigra-[0-9]*:../../graphics/vigra
DEPENDS+=	gnuradio-doxygen-[0-9]*:../../ham/gnuradio-doxygen
DEPENDS+=	uhd-[0-9]*:../../ham/uhd
DEPENDS+=	ibus-qt-[0-9]*:../../inputmethod/ibus-qt
DEPENDS+=	notmuch-[0-9]*:../../mail/notmuch
DEPENDS+=	gnuradio-[0-9]*:../../meta-pkgs/gnuradio
DEPENDS+=	libcarddav-[0-9]*:../../misc/libcarddav
DEPENDS+=	libkate-[0-9]*:../../multimedia/libkate
DEPENDS+=	liboggz-[0-9]*:../../multimedia/liboggz
DEPENDS+=	libtheora-docs-[0-9]*:../../multimedia/libtheora-docs
DEPENDS+=	libjwt-[0-9]*:../../security/libjwt
DEPENDS+=	libnitrokey-[0-9]*:../../security/libnitrokey
DEPENDS+=	json-c-[0-9]*:../../textproc/json-c
DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2
DEPENDS+=	serd-[0-9]*:../../textproc/serd
DEPENDS+=	sord-[0-9]*:../../textproc/sord
DEPENDS+=	${PHP_PKG_PREFIX}-davical-[0-9]*:../../www/davical
DEPENDS+=	libxkbcommon-docs-[0-9]*:../../x11/libxkbcommon-docs

.include "../../mk/bsd.fast.prefs.mk"

.if ${PKG_DEFAULT_OPTIONS:Mdoxygen}
# doxygen option enabled
.else
BROKEN=		"PKG_DEFAULT_OPTIONS must contain doxygen for this to be useful."
.endif
.include "../../lang/php/phpversion.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
