# $NetBSD: Makefile,v 1.1.1.1 2004/12/28 17:10:17 wiz Exp $
#

DISTNAME=		uim-0.4.5
CATEGORIES=		inputmethod
MASTER_SITES=		http://freedesktop.org/~tkng/

MAINTAINER=		VEG03617@nifty.com
HOMEPAGE=		http:/uim.freedesktop.org/
COMMENT=		Uim is a multilingual input method library

BUILD_DEPENDS+=		p5-XML-Parser>=2.34:../../textproc/p5-XML-Parser

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_NCURSES=		# clear_screen, clr_eos
PKGCONFIG_OVERRIDE+=	${WRKSRC}/uim.pc.in
GNU_CONFIGURE=		yes
USE_X11=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-CANDWIN ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SH ${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/XIM-SERVER ${PREFIX}/share/doc/uim

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
