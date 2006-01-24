# $NetBSD: Makefile,v 1.9 2006/01/24 07:32:05 wiz Exp $

.include "../../editors/abiword/Makefile.common"

PKGNAME=	abiword-plugins-${ABIWORD_VERSION}
PKGREVISION=	1
COMMENT=	Plugins enhancing Abiword's capabilities

WRKSRC=		${WRKDIR}/${DISTNAME}/abiword-plugins

BUILD_DEPENDS+=	abiword-${ABIWORD_VERSION}*:../../editors/abiword

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-all --enable-abicommand
CONFIGURE_ARGS+=	--enable-applix --enable-bmp --enable-bz2abw
CONFIGURE_ARGS+=	--enable-clarisworks --enable-docbook --enable-eml
CONFIGURE_ARGS+=	--enable-jpeg --enable-kword --enable-latex
CONFIGURE_ARGS+=	--enable-mswrite --enable-nroff --enable-wml
CONFIGURE_ARGS+=	--enable-xhtml --enable-xsl-fo
CONFIGURE_ARGS+=	--enable-wmf

.include "../../mk/bsd.pkg.mk"
