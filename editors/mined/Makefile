# $NetBSD: Makefile,v 1.3 2003/03/29 12:40:44 jmmv Exp $
#

DISTNAME=	mined-2000.6
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	html-aware editor

USE_BUILDLINK2=	yes

MAKEFILE=	makefile.bsd

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
