# $NetBSD: Makefile,v 1.1.1.1 2004/10/21 06:32:05 xtraeme Exp $
#
.include "../../editors/abiword/Makefile.common"

PKGNAME=	abiword-plugins-${ABIWORD_DIST_VERSION}

COMMENT=	Plugins enhancing Abiword's capabilities

WRKSRC=		${WRKDIR}/${DISTNAME}/abiword-plugins

BUILD_DEPENDS+=	abiword-${ABIWORD_DIST_VERSION}:../../editors/abiword

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-all
CONFIGURE_ARGS+=	--enable-xsl-fo --enable-xhtml --enable-wml
CONFIGURE_ARGS+=	--enable-nrof --enable-mswrite --enable-latex
CONFIGURE_ARGS+=	--enable-kword --enable-jpeg --enable-AbiGdkPixbuf
CONFIGURE_ARGS+=	--enable-eml --enable-docbook --enable-abicommand
CONFIGURE_ARGS+=	--enable-clarisworks --enable-bz2abw --enable-bmp
CONFIGURE_ARGS+=	--enable-applix

.include "../../mk/bsd.pkg.mk"
