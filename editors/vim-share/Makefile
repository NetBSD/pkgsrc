# $NetBSD: Makefile,v 1.5 2001/02/16 14:40:54 wiz Exp $

.include		"Makefile.common"

PKGNAME=		vim-share-${VIM_VERSION}

COMMENT=		Data files for the vim editor (vi clone)

DISTFILES+=		${DISTNAME}-rt${EXTRACT_SUFX}

CONFIGURE_ARGS+=	--disable-gui

INSTALL_TARGET=		installvimhelp installhelplinks installmacros \
			installtutor installtools

post-configure:
	cd ${WRKSRC}/ctags; ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} \
			     ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC}/ctags; ${MAKE}
	cd ${WRKSRC}/xxd; CC="${CC}" CFLAGS="${CFLAGS}" ${MAKE} \
		-f Makefile.unix

.include "../../mk/bsd.pkg.mk"
