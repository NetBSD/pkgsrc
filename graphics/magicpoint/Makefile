# $NetBSD: Makefile,v 1.13 2000/05/01 06:07:45 jlam Exp $

DISTNAME=		magicpoint-1.06a
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=		itojun@itojun.org
HOMEPAGE=		http://www.Mew.org/mgp/

DEPENDS=		freetype-lib-*:../../graphics/freetype-lib

CONFLICTS=		mgp-*

GNU_CONFIGURE=		yes
USE_IMAKE=		yes
CONFIGURE_ARGS=		--disable-vflib --enable-freetype-charset16 \
			--enable-locale
MAKE_ENV+=		LOCAL_LDFLAGS="${LDFLAGS}"

# We need to perform the steps normally done by ``xmkmf -a'' since some
# files need to be created before ``make depend''.
#
XMKMF=			xmkmf

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
	${INSTALL_DATA} README* *.gif *.eps *.mgp *.xbm mgprc-sample \
		${PREFIX}/share/examples/mgp

.include "../../mk/bsd.pkg.mk"
