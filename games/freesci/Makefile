# $NetBSD: Makefile,v 1.7 2004/03/20 15:16:10 wiz Exp $
#

DISTNAME=		freesci-0.3.4a
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www-plan.cs.colorado.edu/reichenb/freesci/ \
			http://teksolv.de/~jameson/

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://freesci.linuxgames.com/
COMMENT=		Interpreter for Sierra On-Line's SCI games

DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/examples/freesci
	${INSTALL_DATA} ${FILESDIR}/config ${LOCALBASE}/share/examples/freesci

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
#.include "../../mk/motif.buildlink3.mk"
#.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
