# $NetBSD: Makefile,v 1.5 2002/02/07 22:52:58 jlam Exp $
#

DISTNAME=	naim-0.11.2-2002-02-04-0919
PKGNAME=	naim-0.11.2.20020204
CATEGORIES=	chat
MASTER_SITES=	http://dev.n.ml.org/ \
		http://dev.n.ml.org/naim-snapshots/00-11-02/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://naim.n.ml.org/
COMMENT=	ncurses-based AIM/IRC client

WRKSRC=		${WRKDIR}/naim-0.11.2
GNU_CONFIGURE=	YES

USE_BUILDLINK_ONLY=	YES
USE_NCURSES=		YES
USE_GNU_READLINE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/naim
	${INSTALL_DATA} ${WRKSRC}/doc/naimrc_sample \
		${PREFIX}/share/examples/naim/dot.naimrc

.include "../../devel/ncurses/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
