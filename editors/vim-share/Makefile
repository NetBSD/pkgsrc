# $NetBSD: Makefile,v 1.6 2001/06/06 06:07:29 pooka Exp $

.include		"Makefile.common"

PKGNAME=		vim-share-${VIM_VERSION}

COMMENT=		Data files for the vim editor (vi clone)

DISTFILES+=		${DISTNAME}-rt${EXTRACT_SUFX}

CONFIGURE_ARGS+=	--disable-gui

INSTALL_TARGET=		installvimhelp installhelplinks installmacros \
			installtutor installtools

do-build:
	cd ${WRKSRC}/xxd; CC="${CC}" CFLAGS="${CFLAGS}" ${MAKE} \
		-f Makefile.unix

.include "../../mk/bsd.pkg.mk"
