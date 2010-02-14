# $NetBSD: Makefile,v 1.41 2010/02/14 08:41:36 obache Exp $
#

.include "../../inputmethod/uim/Makefile.common"

COMMENT=		Multilingual input method library

CONFLICTS+=		uim-qt4-immodule-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool pkg-config msgfmt
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	${WRKSRC}/uim.pc.in
GNU_CONFIGURE=		YES
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

INSTALLATION_DIRS+=	share/doc/uim

post-install:
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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgcroots/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
