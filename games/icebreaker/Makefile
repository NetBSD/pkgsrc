# $NetBSD: Makefile,v 1.1.1.1 2002/03/08 19:19:14 wiz Exp $
#

DISTNAME=	icebreaker-1.2.1
CATEGORIES=	games
MASTER_SITES=	http://www.mattdm.org/icebreaker/1.2.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.mattdm.org/icebreaker/
COMMENT=	penguin capturing simulation

USE_GMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/icebreaker
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/icebreaker

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
