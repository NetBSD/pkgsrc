# $NetBSD: Makefile,v 1.23 2007/12/01 23:58:50 wiz Exp $
#

DISTNAME=		freesci-0.3.5
CATEGORIES=		games
MASTER_SITES=		http://www-plan.cs.colorado.edu/reichenb/freesci/

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://freesci.linuxgames.com/
COMMENT=		Interpreter for Sierra On-Line's SCI games

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-ggi --without-directfb

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/freesci
	${INSTALL_DATA} ${FILESDIR}/config ${PREFIX}/share/examples/freesci

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
#.include "../../mk/motif.buildlink3.mk"
#.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
