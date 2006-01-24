# $NetBSD: Makefile,v 1.15 2006/01/24 07:32:08 wiz Exp $
#

DISTNAME=		freesci-0.3.4c
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		http://www-plan.cs.colorado.edu/reichenb/freesci/ \
			http://teksolv.de/~jameson/

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
.include "../../fonts/Xft2/buildlink3.mk"
#.include "../../mk/motif.buildlink3.mk"
#.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
