# $NetBSD: Makefile,v 1.111 2016/03/05 11:28:43 jperkin Exp $
#

.include "../../inputmethod/uim/Makefile.common"

PKGREVISION=		27
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
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

LDFLAGS.SunOS+=	-mimpure-text
CFLAGS.SunOS+=	-std=c99 -D__EXTENSIONS__

.include "options.mk"

PKG_SYSCONFSUBDIR=	uim
INSTALLATION_DIRS+=	share/doc/uim

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

EGDIR=			${PREFIX}/share/examples/uim
CONF_FILES=		${EGDIR}/loader.scm \
			${PKG_SYSCONFDIR}/loader.scm
CONF_FILES+=		${EGDIR}/installed-modules.scm \
			${PKG_SYSCONFDIR}/installed-modules.scm

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
_BUILDING_UIM=	YES
.include "modules.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcroots+=	libgcroots>=0.2.3
.include "../../devel/libgcroots/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
