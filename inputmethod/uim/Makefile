# $NetBSD: Makefile,v 1.34 2008/09/24 03:03:45 obache Exp $
#

DISTNAME=		uim-1.5.1
CATEGORIES=		inputmethod
MASTER_SITES=		http://uim.googlecode.com/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		VEG03617@nifty.com
HOMEPAGE=		http://code.google.com/p/uim/
COMMENT=		Multilingual input method library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
USE_NCURSES=		YES	# clear_screen, clr_eos
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool pkg-config msgfmt
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	${WRKSRC}/uim.pc.in
GNU_CONFIGURE=		YES
GTK2_IMMODULES=		YES
CONFIGURE_ARGS+=	--disable-emacs
CONFIGURE_ARGS+=	--with-libgcroots=installed

.include "options.mk"

PLIST_VARS+=		editline
CHECK_BUILTIN.readline:=	yes
.include "../../devel/readline/builtin.mk"
CHECK_BUILTIN.readline:=	no

.if !empty(BUILTIN_LIB_FOUND.edit:M[yY][eE][sS])
PLIST.editline=		yes
.else
CONFIGURE_ARGS+=	--with-libedit=no
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/COMPATIBILITY ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/CUSTOM ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/DOT-UIM ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-CANDWIN ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-PROTOCOL ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/PLUGIN ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SCM ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SH ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/uim/uim-fep
	${INSTALL_DATA} ${WRKSRC}/fep/README ${DESTDIR}${PREFIX}/share/doc/uim/uim-fep
	${INSTALL_DATA} ${WRKSRC}/fep/README.ja ${DESTDIR}${PREFIX}/share/doc/uim/uim-fep

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgcroots/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
