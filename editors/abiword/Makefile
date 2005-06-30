# $NetBSD: Makefile,v 1.91 2005/06/30 13:16:51 adam Exp $

.include "Makefile.common"
PKGNAME=	abiword-${ABIWORD_VERSION}
COMMENT=	Open Source cross-platform word processor

# GTK1 version and previous name of the GTK2 version
CONFLICTS=	abiword-personal-[0-9]* abiword2-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/abi
USE_TOOLS+=	perl

REPLACE_PERL=	user/wp/scripts/abw2html.pl

PKG_OPTIONS_VAR=	PKG_OPTIONS.abiword
PKG_SUPPORTED_OPTIONS=	gucharmap

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

.if empty(PKG_OPTIONS:Mgucharmap)
CONFIGURE_ARGS+=	--disable-gucharmap
.endif
CONFIGURE_ARGS+=	--with-sys-wv
.if ${OPSYS} == "Darwin"
# hardcode relative install path in libwv (MacOS X only)
CONFIGURE_ARGS+=	--without-epath
# Use X11 instead of Cocoa API
CONFIGURE_ARGS+=	--disable-Cocoa
.endif
CONFIGURE_ARGS+=	--enable-threads --with-libxml2
CONFIGURE_ARGS+=	--with-libjpeg-prefix=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
USE_GNU_ICONV=		yes

post-install:
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/abiword-docs/man/abiword.1 \
		${PREFIX}/man/man1/abiword.1
	cd ${WRKDIR}/${DISTNAME}/abiword-docs/ && env \
		ABI_DOC_DEST=${PREFIX}/share/AbiSuite-2.2/AbiWord \
		./make-html.sh

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/wv/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mgucharmap)
.include "../../fonts/gucharmap/buildlink3.mk"
.endif

.include "../../textproc/enchant/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
