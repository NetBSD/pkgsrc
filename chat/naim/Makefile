# $NetBSD: Makefile,v 1.1.1.1 2002/01/25 15:53:56 tv Exp $
#

PKGNAME=	naim-0.11.1.20020123
DISTNAME=	naim-0.11.1-2002-01-23-2329
CATEGORIES=	chat
MASTER_SITES=	http://dev.n.ml.org/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://naim.n.ml.org/
COMMENT=	ncurses-based AIM/IRC client

WRKSRC=		${WRKDIR}/naim-0.11.1
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
