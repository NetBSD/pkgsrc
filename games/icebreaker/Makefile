# $NetBSD: Makefile,v 1.3 2002/08/27 18:49:10 jlam Exp $
#

DISTNAME=	icebreaker-1.2.1
CATEGORIES=	games
MASTER_SITES=	http://www.mattdm.org/icebreaker/1.2.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.mattdm.org/icebreaker/
COMMENT=	penguin capturing simulation

USE_BUILDLINK2=	yes
USE_GMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/icebreaker
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/icebreaker

.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
