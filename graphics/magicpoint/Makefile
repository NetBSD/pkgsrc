# $NetBSD: Makefile,v 1.22 2001/05/22 09:32:21 wiz Exp $

DISTNAME=		magicpoint-1.07a
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=		itojun@itojun.org
HOMEPAGE=		http://www.Mew.org/mgp/
COMMENT=		X11 based presentation tool

DEPENDS+=		freetype-lib>=1.3.1:../../graphics/freetype-lib
DEPENDS+=		png>=1.0.11:../../graphics/png

CONFLICTS=		mgp-*

GNU_CONFIGURE=		yes
USE_IMAKE=		yes
CONFIGURE_ARGS=		--disable-vflib --enable-freetype-charset16 \
			--enable-locale
CONFIGURE_ENV+=		LIBS="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -L${X11BASE}/lib -lintl"		# needed so -lttf works

# We need to perform the steps normally done by ``xmkmf -a'' since some
# files need to be created before ``make depend''.
#
XMKMF=			${X11BASE}/bin/xmkmf

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

.include "../../mk/bsd.pkg.mk"
