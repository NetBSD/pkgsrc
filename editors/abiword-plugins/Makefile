# $NetBSD: Makefile,v 1.5 2005/02/07 14:15:13 adam Exp $

.include "../../editors/abiword/Makefile.common"

PKGNAME=	abiword-plugins-${ABIWORD_DIST_VERSION}
COMMENT=	Plugins enhancing Abiword's capabilities

WRKSRC=		${WRKDIR}/${DISTNAME}/abiword-plugins

BUILD_DEPENDS+=	abiword-${ABIWORD_DIST_VERSION}*:../../editors/abiword

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-all --enable-AbiGdkPixbuf --enable-abicommand
CONFIGURE_ARGS+=	--enable-applix --enable-bmp --enable-bz2abw
CONFIGURE_ARGS+=	--enable-clarisworks --enable-docbook --enable-eml
CONFIGURE_ARGS+=	--enable-jpeg --enable-kword --enable-latex
CONFIGURE_ARGS+=	--enable-mswrite --enable-nroff --enable-wml
CONFIGURE_ARGS+=	--enable-xhtml --enable-xsl-fo

.include "../../mk/bsd.pkg.mk"
