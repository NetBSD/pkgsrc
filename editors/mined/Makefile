# $NetBSD: Makefile,v 1.5 2003/07/01 15:52:00 agc Exp $
#

DISTNAME=	mined-2000.7
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	html-aware editor

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK2=	yes

MAKEFILE=	makefile.bsd

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
