# $NetBSD: Makefile,v 1.1.1.1 2003/03/05 14:25:36 agc Exp $
#

DISTNAME=	mined-2000.5
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	html-aware editor

USE_BUILDLINK2=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAKEFILE=	makefile.bsd

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
