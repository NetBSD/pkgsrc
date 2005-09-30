# $NetBSD: Makefile,v 1.13 2005/09/30 12:43:35 wiz Exp $
#

DISTNAME=		uim-0.4.9.1
CATEGORIES=		inputmethod
MASTER_SITES=		http://uim.freedesktop.org/releases/

MAINTAINER=		VEG03617@nifty.com
HOMEPAGE=		http://uim.freedesktop.org/wiki/
COMMENT=		Multilingual input method library

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_NCURSES=		# clear_screen, clr_eos
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/uim.pc.in
GNU_CONFIGURE=		YES
GTK2_IMMODULES=		YES

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/README.ja ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-CANDWIN ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-PROTOCOL ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/PLUGIN ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SCM ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SH ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/XIM-SERVER ${PREFIX}/share/doc/uim
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uim/uim-fep
	${INSTALL_DATA} ${WRKSRC}/fep/README ${PREFIX}/share/doc/uim/uim-fep
	${INSTALL_DATA} ${WRKSRC}/fep/README.ja ${PREFIX}/share/doc/uim/uim-fep

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
