# $NetBSD: Makefile,v 1.3 2002/02/06 14:40:38 tv Exp $
#

PKGNAME=	naim-0.11.2.20020204
DISTNAME=	naim-0.11.2-2002-02-04-0919
CATEGORIES=	chat
MASTER_SITES=	http://dev.n.ml.org/

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
