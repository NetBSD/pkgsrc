# $NetBSD: Makefile,v 1.144 2020/11/21 09:34:56 wiz Exp $

DISTNAME=	cups-filters-1.28.5
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://openprinting.org/download/cups-filters/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.linuxfoundation.org/collaborate/workgroups/openprinting/cups-filters
COMMENT=	Backends, filters, and other software for cups
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND mit

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		bash:run pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-braille
CONFIGURE_ARGS+=	--disable-ldap
CONFIGURE_ARGS+=	--disable-mutool
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-apple-raster-filter=rastertopdf
CONFIGURE_ARGS+=	--with-gs-path=${PREFIX}/bin/gs
CONFIGURE_ARGS+=	--with-pdftops-path=${PREFIX}/bin/pdftops
CONFIGURE_ARGS+=	--with-shell=${TOOLS_PATH.bash}
CONFIGURE_ARGS+=	--with-test_font_path=${PREFIX}/share/fonts/X11/TTF/DejaVuSans.ttf

PKGCONFIG_OVERRIDE+=	libcupsfilters.pc.in
PKGCONFIG_OVERRIDE+=	libfontembed.pc.in

CONFLICTS+=	cups<1.6

REPLACE_BASH+=	filter/braille/drivers/generic/brftoembosser.in
REPLACE_BASH+=	filter/braille/drivers/index/imageubrltoindexv3.in
REPLACE_BASH+=	filter/braille/drivers/index/imageubrltoindexv4.in
REPLACE_BASH+=	filter/braille/drivers/index/textbrftoindexv3.in
REPLACE_BASH+=	filter/braille/filters/brftopagedbrf.in
REPLACE_BASH+=	filter/braille/filters/imagetobrf.in
REPLACE_BASH+=	filter/braille/filters/texttobrf.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CFLAGS+=	-framework IOKit
.endif

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

BUILD_DEFS+=		VARBASE

RCD_SCRIPTS=		cups-browsed
CONF_FILES+=		${PREFIX}/share/examples/cups-filters/cups-browsed.conf ${PKG_SYSCONFDIR}/cups/cups-browsed.conf

TEST_TARGET=		check

post-extract:
	${CP} ${FILESDIR}/cups-browsed-daemonize.sh ${WRKSRC}

SUBST_CLASSES+=			daemonize
SUBST_STAGE.daemonize=		pre-configure
SUBST_MESSAGE.daemonize=	Customizing daemonizing script
SUBST_FILES.daemonize=		cups-browsed-daemonize.sh
SUBST_VARS.daemonize=		PREFIX VARBASE

INSTALLATION_DIRS+=		share/examples/cups-filters

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/cups/cups-browsed.conf \
		${DESTDIR}${PREFIX}/share/examples/cups-filters/cups-browsed.conf
	# backends that need root access should not have world read and execute permissions
	${CHMOD} go-rwx ${DESTDIR}${PREFIX}/libexec/cups/backend/parallel
	${CHMOD} go-rwx ${DESTDIR}${PREFIX}/libexec/cups/backend/serial
	${INSTALL_SCRIPT} ${WRKSRC}/cups-browsed-daemonize.sh ${DESTDIR}${PREFIX}/libexec/cups-browsed

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../print/ijs/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/qpdf/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
