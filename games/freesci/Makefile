# $NetBSD: Makefile,v 1.5 2004/02/14 17:21:40 jlam Exp $
#

DISTNAME=		freesci-0.3.4a
CATEGORIES=		games
MASTER_SITES=		http://savannah.nongnu.org/download/freesci/stable.pkg/0.3.4a/

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://freesci.linuxgames.com/
COMMENT=		Interpreter for Sierra On-Line's SCI games

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
