# $NetBSD: Makefile,v 1.86 2005/02/10 19:27:32 wiz Exp $

.include "Makefile.common"
PKGNAME=	abiword-${ABIWORD_DIST_VERSION}
PKGREVISION=	1
COMMENT=	Open Source cross-platform word processor

# GTK1 version and previous name of the GTK2 version
CONFLICTS=	abiword-personal-[0-9]* abiword2-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/abi
USE_PERL5=	run

REPLACE_PERL=	user/wp/scripts/abw2html.pl

PKG_OPTIONS_VAR=	PKG_OPTIONS.abiword
PKG_SUPPORTED_OPTIONS=	gucharmap

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Mgucharmap)
CONFIGURE_ARGS+=	--enable-gucharmap
.endif
CONFIGURE_ARGS+=	--with-sys-wv
.if ${OPSYS} == "Darwin"
# hardcode relative install path in libwv (MacOS X only)
CONFIGURE_ARGS+=	--without-epath
# Use X11 instead of Cocoa API
CONFIGURE_ARGS+=	--disable-Cocoa
.endif
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

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
