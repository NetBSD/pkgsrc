# $NetBSD: Makefile,v 1.27 2006/09/16 12:05:16 hira Exp $
#

DISTNAME=		uim-1.2.1
PKGREVISION=		1
CATEGORIES=		inputmethod
MASTER_SITES=		http://uim.freedesktop.org/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		VEG03617@nifty.com
HOMEPAGE=		http://uim.freedesktop.org/wiki/
COMMENT=		Multilingual input method library

USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
USE_NCURSES=		# clear_screen, clr_eos
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool pkg-config
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	${WRKSRC}/uim.pc.in
GNU_CONFIGURE=		YES
GTK2_IMMODULES=		YES
CONFIGURE_ARGS+=	--disable-emacs

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/DOT-UIM ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-CANDWIN ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-PROTOCOL ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/PLUGIN ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SCM ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SH ${PREFIX}/share/doc/uim
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uim/uim-fep
	${INSTALL_DATA} ${WRKSRC}/fep/README ${PREFIX}/share/doc/uim/uim-fep
	${INSTALL_DATA} ${WRKSRC}/fep/README.ja ${PREFIX}/share/doc/uim/uim-fep

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
