# $NetBSD: Makefile,v 1.31 2002/07/05 12:16:33 wiz Exp $

DISTNAME=		magicpoint-1.09a
PKGREVISION=		1
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=		itojun@itojun.org
HOMEPAGE=		http://www.Mew.org/mgp/
COMMENT=		X11 based presentation tool

CONFLICTS=		mgp-[0-9]*

GNU_CONFIGURE=		yes
USE_IMAKE=		yes
CONFIGURE_ARGS+=	--enable-freetype-charset16
CONFIGURE_ARGS+=	--disable-vflib
CONFIGURE_ARGS+=	--enable-locale
CONFIGURE_ARGS+=	--enable-gif

# We need to perform the steps normally done by ``xmkmf -a'' since some
# files need to be created before ``make depend''.
#
XMKMF=			${XMKMF_CMD} ${XMKMF_FLAGS}

post-configure:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ctlwords.h
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} grammar.c
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} scanner.c
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} tokdefs.h
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} Makefiles
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} includes
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} depend

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mgp
	cd ${WRKSRC}; \
	${INSTALL_DATA} COPYRIGHT COPYRIGHT.jp FAQ \
		README README.fonts README.fonts.jp README.lang \
		SYNTAX USAGE USAGE.jp ${PREFIX}/share/doc/mgp
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mgp
	cd ${WRKSRC}/sample; \
	${INSTALL_DATA} README* *.jpg *.eps *.mgp *.xbm mgprc-sample \
		${PREFIX}/share/examples/mgp

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../graphics/libungif/buildlink.mk"
.include "../../graphics/mng/buildlink.mk"
.include "../../graphics/netpbm/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../print/ja-vflib-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
