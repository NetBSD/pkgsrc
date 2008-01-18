# $NetBSD: Makefile,v 1.25 2008/01/18 05:06:31 tnn Exp $

.include "../../editors/abiword/Makefile.common"

PKGNAME=	abiword-plugins-${ABIWORD_VERSION}
PKGREVISION=	4
COMMENT=	Plugins enhancing Abiword's capabilities

WRKSRC=		${WRKDIR}/${DISTNAME}/abiword-plugins

BUILD_DEPENDS+=	abiword-${ABIWORD_VERSION}{,nb*}:../../editors/abiword

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-all
CONFIGURE_ARGS+=	--enable-OpenDocument
CONFIGURE_ARGS+=	--enable-OpenWriter
CONFIGURE_ARGS+=	--enable-abicapi
CONFIGURE_ARGS+=	--enable-abicommand
CONFIGURE_ARGS+=	--enable-abidash
CONFIGURE_ARGS+=	--enable-applix
CONFIGURE_ARGS+=	--enable-babelfish
CONFIGURE_ARGS+=	--enable-bmp
CONFIGURE_ARGS+=	--enable-bz2abw
CONFIGURE_ARGS+=	--enable-clarisworks
CONFIGURE_ARGS+=	--enable-docbook
CONFIGURE_ARGS+=	--enable-eml
CONFIGURE_ARGS+=	--enable-freetranslation
CONFIGURE_ARGS+=	--enable-gdict
CONFIGURE_ARGS+=	--enable-google
CONFIGURE_ARGS+=	--enable-hancom
CONFIGURE_ARGS+=	--enable-hrtext
CONFIGURE_ARGS+=	--enable-iscii-text
CONFIGURE_ARGS+=	--enable-jpeg
CONFIGURE_ARGS+=	--enable-kword
CONFIGURE_ARGS+=	--enable-latex
CONFIGURE_ARGS+=	--enable-mif
CONFIGURE_ARGS+=	--enable-mswrite
CONFIGURE_ARGS+=	--enable-nroff
CONFIGURE_ARGS+=	--enable-passepartout
CONFIGURE_ARGS+=	--enable-sdw
CONFIGURE_ARGS+=	--enable-t602
CONFIGURE_ARGS+=	--enable-urldict
CONFIGURE_ARGS+=	--enable-wikipedia
CONFIGURE_ARGS+=	--enable-wmf
CONFIGURE_ARGS+=	--enable-wml
CONFIGURE_ARGS+=	--enable-wordperfect
CONFIGURE_ARGS+=	--enable-xhtml
CONFIGURE_ARGS+=	--enable-xsl-fo

.include "../../converters/libwpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
