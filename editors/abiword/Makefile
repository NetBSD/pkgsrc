# $NetBSD: Makefile,v 1.114 2008/01/18 05:06:31 tnn Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"
PKGREVISION=	5

COMMENT=	Open Source cross-platform word processor

# GTK1 version and previous name of the GTK2 version
CONFLICTS=	abiword-personal-[0-9]* abiword2-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/abi
USE_TOOLS+=	perl

REPLACE_SH+=	${WRKDIR}/${DISTNAME}/abiword-docs/make-html.sh
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

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/AbiSuite-2.4/AbiWord

post-build:
	cd ${WRKDIR}/${DISTNAME}/abiword-docs/ && env \
		ABI_DOC_DEST=${WRKDIR} \
		ABI_DOC_PROG=${WRKSRC}/src/wp/main/unix/AbiWord-2.4 \
		./make-html.sh
	find ${WRKDIR}/help -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	find ${WRKDIR}/help \( -name "*.abw.orig" -o -name "*.abw"	\
		-o -name "*.info" -o -name "*.xhtml" \) -print | ${XARGS} ${RM} -f

post-install:
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/abiword-docs/man/abiword.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/abiword.1
	cp -R ${WRKDIR}/help ${DESTDIR}${PREFIX}/share/AbiSuite-2.4/AbiWord/

.if !empty(PKG_OPTIONS:Mgucharmap)
.include "../../fonts/gucharmap/buildlink3.mk"
.endif

.include "../../textproc/enchant/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
