# $NetBSD: Makefile,v 1.7 2012/09/15 11:59:11 obache Exp $

.include		"../../inputmethod/uim/Makefile.common"
PKGNAME=		${EMACS_PKGNAME_PREFIX}uim-elisp-${UIM_VERSION}
CATEGORIES=		inputmethod editors

COMMENT=		Emacs LISP for inputmethod/uim
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt pkg-config 
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-libgcroots=installed
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--with-libedit=no

EMACS_MODULES=		base leim

BUILD_DIRS=		emacs

INSTALLATION_DIRS+=	share/doc/uim/emacs

post-configure:
	${LN} -s ${BUILDLINK_PREFIX.uim}/lib/libuim-scm.la ${WRKSRC}/uim
	${LN} -s ${BUILDLINK_PREFIX.uim}/lib/libuim.la ${WRKSRC}/uim

post-install:
	${INSTALL_DATA} ${WRKSRC}/emacs/README ${DESTDIR}${PREFIX}/share/doc/uim/emacs
	${INSTALL_DATA} ${WRKSRC}/emacs/README.ja ${DESTDIR}${PREFIX}/share/doc/uim/emacs

.include "../../editors/emacs/modules.mk"
.include "../../inputmethod/uim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
