# $NetBSD: Makefile,v 1.4 2000/04/16 07:31:12 mycroft Exp $

.include		"Makefile.common"

PKGNAME=		vim-share-${VIM_VERSION}

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
