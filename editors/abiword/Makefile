# $NetBSD: Makefile,v 1.82 2004/11/22 13:31:46 adam Exp $

.include "Makefile.common"

PKGNAME=	abiword-${ABIWORD_DIST_VERSION}
COMMENT=	Open Source cross-platform word processor

# GTK1 version and previous name of the GTK2 version
CONFLICTS=	abiword-personal-[0-9]* abiword2-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/abi

REPLACE_PERL=	user/wp/scripts/abw2html.pl

PKG_OPTIONS_VAR=	PKG_OPTIONS.abiword
PKG_SUPPORTED_OPTIONS=	gucharmap

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Mgucharmap)
CONFIGURE_ARGS+=	--enable-gucharmap
.endif
CONFIGURE_ARGS+=	--with-sys-wv
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

post-install:
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/abiword-docs/man/abiword.1 \
		${PREFIX}/man/man1/abiword.1
	cd ${WRKDIR}/${DISTNAME}/abiword-docs/ && ${MAKE}

SUBST_CLASSES+=		docs
SUBST_STAGE.docs=	post-patch
SUBST_FILES.docs=	${WRKDIR}/${DISTNAME}/abiword-docs/Makefile
SUBST_SED.docs=		-e "s,prefix = /usr/local,prefix = ${PREFIX}," \
			-e "s,SHELL = /bin/sh,SHELL = ${SH},"
SUBST_MESSAGE.docs=	"Fixing docs Makefile."

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/wv/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mgucharmap)
.include "../../fonts/gucharmap/buildlink3.mk"
.endif

.include "../../textproc/enchant/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
