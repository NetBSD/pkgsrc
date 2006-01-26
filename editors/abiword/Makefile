# $NetBSD: Makefile,v 1.96 2006/01/26 23:23:08 adam Exp $

.include "Makefile.common"
COMMENT=	Open Source cross-platform word processor
PKGREVISION=	2

# GTK1 version and previous name of the GTK2 version
CONFLICTS=	abiword-personal-[0-9]* abiword2-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/abi
USE_TOOLS+=	perl

REPLACE_PERL+=	user/wp/scripts/abw2html.pl

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
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-libjpeg-prefix=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-libxml2
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

USE_GNU_ICONV=		yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-build:
	cd ${WRKDIR}/${DISTNAME}/abiword-docs/ && env \
		ABI_DOC_DEST=${WRKDIR} \
		ABI_DOC_PROG=${WRKSRC}/src/wp/main/unix/AbiWord-2.4 \
		./make-html.sh
	${FIND} ${WRKDIR}/help -type d -exec ${CHMOD} ${PKGDIRMODE} "{}" \;
	${FIND} ${WRKDIR}/help \( -name "*.abw.orig" -or -name "*.abw"	\
		-or -name "*.info" -or -name "*.xhtml" \) -exec ${RM} "{}" \;

post-install:
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/abiword-docs/man/abiword.1 \
		${PREFIX}/${PKGMANDIR}/man1/abiword.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/AbiSuite-2.4/AbiWord
	${CP} -R ${WRKDIR}/help ${PREFIX}/share/AbiSuite-2.4/AbiWord/

.if !empty(PKG_OPTIONS:Mgucharmap)
.include "../../fonts/gucharmap/buildlink3.mk"
.endif

.include "../../textproc/enchant/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
