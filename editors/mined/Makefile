# $NetBSD: Makefile,v 1.11 2004/04/11 08:19:54 snj Exp $
#

DISTNAME=	mined-2000.7
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	Html-aware editor

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=	yes

MAKEFILE=	makefile.bsd

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
