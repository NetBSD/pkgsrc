# $NetBSD: Makefile,v 1.2 2003/03/27 12:56:21 agc Exp $
#

DISTNAME=	mined-2000.6
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
