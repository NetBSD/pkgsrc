# $NetBSD: Makefile,v 1.3 2005/01/04 10:29:15 wiz Exp $
#

DISTNAME=		uim-0.4.5
PKGREVISION=		1
CATEGORIES=		inputmethod
MASTER_SITES=		http://freedesktop.org/~tkng/

MAINTAINER=		VEG03617@nifty.com
HOMEPAGE=		http:/uim.freedesktop.org/
COMMENT=		Uim is a multilingual input method library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_NCURSES=		# clear_screen, clr_eos
PKGCONFIG_OVERRIDE+=	${WRKSRC}/uim.pc.in
GNU_CONFIGURE=		yes
USE_X11=		yes
GTK2_IMMODULES=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-CANDWIN ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SH ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/XIM-SERVER ${PREFIX}/share/doc/uim

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
