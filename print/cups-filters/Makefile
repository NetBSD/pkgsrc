# $NetBSD: Makefile,v 1.71 2017/05/21 09:44:06 leot Exp $

DISTNAME=	cups-filters-1.14.0
CATEGORIES=	print
MASTER_SITES=	http://openprinting.org/download/cups-filters/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/openprinting/cups-filters
COMMENT=	Backends, filters, and other software for cups
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bash:run pkg-config gmake
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils

PKGCONFIG_OVERRIDE+=	libcupsfilters.pc.in
PKGCONFIG_OVERRIDE+=	libfontembed.pc.in

CONFLICTS+=	cups<1.6

REPLACE_BASH+=	filter/braille/drivers/generic/brftoembosser.in
REPLACE_BASH+=	filter/braille/drivers/index/imageubrltoindexv3.in
REPLACE_BASH+=	filter/braille/drivers/index/imageubrltoindexv4.in
REPLACE_BASH+=	filter/braille/drivers/index/textbrftoindexv3.in
REPLACE_BASH+=	filter/braille/filters/imagetobrf.in
REPLACE_BASH+=	filter/braille/filters/texttobrf.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CFLAGS+=	-framework IOKit
.endif

.if ${INIT_SYSTEM} == "rc.d"
CONFIGURE_ARGS+=	--with-rcdir=${PREFIX}/share/examples/rc.d
CONFIGURE_ARGS+=	--with-rclevels=""
.endif
CONFIGURE_ARGS+=	--disable-braille
CONFIGURE_ARGS+=	--disable-ldap
CONFIGURE_ARGS+=	--disable-mutool
CONFIGURE_ARGS+=	--with-apple-raster-filter=rastertopdf
CONFIGURE_ARGS+=	--with-shell=${TOOLS_PATH.bash}
CONFIGURE_ARGS+=	--with-pdftops-path=${PREFIX}/bin/pdftops
CONFIGURE_ARGS+=	--with-gs-path=${PREFIX}/bin/gs

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/cups-filters

CONF_FILES=		${PREFIX}/share/examples/cups-filters/fonts/conf.d/99pdftoopvp.conf ${PKG_SYSCONFDIR}/fontconfig/conf.d/99pdftoopvp.conf
CONF_FILES+=		${PREFIX}/share/examples/cups-filters/cups-browsed.conf ${PKG_SYSCONFDIR}/cups/cups-browsed.conf

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/cups/cups-browsed.conf ${DESTDIR}${PREFIX}/share/examples/cups-filters/cups-browsed.conf
	# backends that need root access should not have world read and execute permissions
	${CHMOD} go-rwx ${DESTDIR}${PREFIX}/libexec/cups/backend/parallel
	${CHMOD} go-rwx ${DESTDIR}${PREFIX}/libexec/cups/backend/serial

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.cups+=	cups>=1.7.4nb1
.include "../../print/cups/buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../print/ijs/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.poppler-includes?=	poppler-includes>=0.26.1nb1
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/qpdf/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
