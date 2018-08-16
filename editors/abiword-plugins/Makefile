# $NetBSD: Makefile,v 1.91 2018/08/16 18:54:43 adam Exp $

.include	"../../editors/abiword/Makefile.common"
DISTNAME=	abiword-${ABIVERSION}
PKGNAME=	abiword-plugins-${ABIVERSION}
PKGREVISION=	30
CATEGORIES=	editors
MASTER_SITES=	http://www.abiword.com/downloads/abiword/${PKGVERSION_NOREV}/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.abiword.com/
COMMENT=	Open Source cross-platform word processor
LICENSE=	gnu-gpl-v2

DISTINFO_FILE=	${.CURDIR}/../../editors/abiword/distinfo
PATCHDIR=	${.CURDIR}/../../editors/abiword/patches

CONFLICTS=      abiword-plugins-[0-9]* abiword-personal-[0-9]* abiword2-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake pkg-config
USE_LANGUAGES=	c c++

BUILD_DIRS=	plugins

# All configure_args here
CONFIGURE_ARGS+=	--disable-default-plugins	#do not build any plugins by default
CONFIGURE_ARGS+=	--enable-builtin-plugins
CONFIGURE_ARGS+=	--enable-spell         # (Gtk+ only) include spell checking support
CONFIGURE_ARGS+=	--with-inter7eps=no

# evolution data server can't be found even if buildlinked
# disable to make sure it's not found somewhere else
CONFIGURE_ARGS+=        --with-evolution-data-server=no

# Disabled plugins: gda rsvg mathview
# rsvg is not needed with gtk, we don't have libgnomedb
# and mathview doesn't work (in future versions mathveiw uses
# lasem instead of gtkmathview, it might work)
CONFIGURE_ARGS+=	--enable-plugins="\
	aiksaurus \
	applix \
	babelfish \
	bmp \
	clarisworks \
	collab \
	command \
	docbook \
	eml \
	epub \
	freetranslation \
	garble \
	gdict \
	gimp \
	goffice \
	google \
	grammar \
	hancom \
	hrtext \
	iscii \
	kword \
	latex \
	loadbindings \
	mht \
	mif \
	mswrite \
	opendocument \
	openwriter \
	openxml \
	opml \
	ots \
	paint \
	passepartout \
	pdb \
	pdf \
	presentation \
	psion \
	s5 \
	sdw \
	t602 \
	urldict \
	wikipedia \
	wmf \
	wml \
	wordperfect \
	wpg \
	xslfo"


PKGCONFIG_OVERRIDE+=	libabiword.pc.in

pre-configure:
	cd ${WRKSRC}; \
	autoreconf --force --install

BUILDLINK_TRANSFORM+=	opt:-no-undefined:-Wl,--no-undefined

.include "../../editors/abiword/options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/psiconv/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/libwps/buildlink3.mk"
.include "../../chat/loudmouth/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/asio/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../editors/abiword/buildlink3.mk"
.include "../../geography/libchamplain012/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/goffice0.10/buildlink3.mk"
#.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/aiksaurus/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/link-grammar/buildlink3.mk"
.include "../../textproc/ots/buildlink3.mk"
.include "../../textproc/rasqal/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../www/tidy/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
