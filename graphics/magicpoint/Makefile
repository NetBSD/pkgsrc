# $NetBSD: Makefile,v 1.36 2004/01/03 18:49:43 reed Exp $

DISTNAME=		magicpoint-1.10a
PKGREVISION=		1
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=		itojun@itojun.org
HOMEPAGE=		http://www.Mew.org/mgp/
COMMENT=		X11 based presentation tool

CONFLICTS=		mgp-[0-9]*

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_IMAKE=		yes
USE_PERL5=		build

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

.include "../../fonts/Xft2/buildlink2.mk"
.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/netpbm/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
