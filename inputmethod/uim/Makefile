# $NetBSD: Makefile,v 1.97 2014/05/15 14:41:53 adam Exp $
#

.include "../../inputmethod/uim/Makefile.common"

PKGREVISION=		13
COMMENT=		Multilingual input method library
#LICENSE=		See ${WRKSRC}/COPYING

CONFLICTS+=		uim-qt4-immodule-[0-9]*

USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool pkg-config msgfmt
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	${WRKSRC}/uim.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-emacs
CONFIGURE_ARGS+=	--with-libgcroots=installed

LDFLAGS.SunOS+=	-mimpure-text
CFLAGS.SunOS+=	-std=c99 -D__EXTENSIONS__

.include "options.mk"

MAKE_DIRS+=		etc/uim
INSTALLATION_DIRS+=	share/doc/uim share/examples/uim

EGDIR=			${PREFIX}/share/examples/uim
CONF_FILES=		${EGDIR}/loader.scm.example \
			${PKG_SYSCONFDIR}/uim/loader.scm
CONF_FILES+=		${EGDIR}/installed-modules.scm.example \
			${PKG_SYSCONFDIR}/uim/installed-modules.scm

post-install:
# Register uim module infomation
	${MKDIR} ${DESTDIR}${PREFIX}/share/uim/pkgsrc
.for m in ${UIM_MODULES}
	${TOUCH} ${DESTDIR}${PREFIX}/share/uim/pkgsrc/${m}
.endfor
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
# loader.scm and installed-modules.scm is updated by uim-module-manager.
	${MV} ${DESTDIR}${PREFIX}/etc/uim/loader.scm \
		${DESTDIR}${EGDIR}/loader.scm.example
	${MV} ${DESTDIR}${PREFIX}/etc/uim/installed-modules.scm \
		${DESTDIR}${EGDIR}/installed-modules.scm.example

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcroots+=	libgcroots>=0.2.3
.include "../../devel/libgcroots/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
