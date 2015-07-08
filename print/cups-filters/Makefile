# $NetBSD: Makefile,v 1.22.2.1 2015/07/08 19:47:19 tron Exp $

DISTNAME=	cups-filters-1.0.71
CATEGORIES=	print
MASTER_SITES=	http://openprinting.org/download/cups-filters/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/openprinting/cups-filters
COMMENT=	Backends, filters, and other software for cups
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bash:run pkg-config
USE_TOOLS+=	autoconf
USE_LANGUAGES=	c c++

CONFLICTS+=	cups<1.6
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils

PKGCONFIG_OVERRIDE+=	libcupsfilters.pc.in
PKGCONFIG_OVERRIDE+=	libfontembed.pc.in

REPLACE_BASH+=	filter/textonly

CONFIGURE_ARGS+=	--with-rcdir=${PREFIX}/share/examples/rc.d
CONFIGURE_ARGS+=	--with-rclevels=""
CONFIGURE_ARGS+=	--with-shell=${TOOLS_PATH.bash}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/cups-filters

CONF_FILES=		${PREFIX}/share/examples/cups-filters/fonts/conf.d/99pdftoopvp.conf ${PKG_SYSCONFDIR}/fonts/conf.d/99pdftoopvp.conf
CONF_FILES=		${PREFIX}/share/examples/cups-filters/cups-browsed.conf ${PKG_SYSCONFDIR}/cups/cups-browsed.conf

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/cups/cups-browsed.conf ${DESTDIR}${PREFIX}/share/examples/cups-filters/cups-browsed.conf

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
