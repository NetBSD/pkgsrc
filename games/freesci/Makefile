# $NetBSD: Makefile,v 1.6 2004/03/08 19:40:38 jmmv Exp $
#

DISTNAME=		freesci-0.3.4a
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://savannah.nongnu.org/download/freesci/stable.pkg/0.3.4a/

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://freesci.linuxgames.com/
COMMENT=		Interpreter for Sierra On-Line's SCI games

DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/examples/freesci
	${INSTALL_DATA} ${FILESDIR}/config ${LOCALBASE}/share/examples/freesci

.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
#.include "../../mk/motif.buildlink2.mk"
#.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
