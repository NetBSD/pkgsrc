# $NetBSD: Makefile,v 1.12 2004/10/03 00:14:39 tv Exp $
#

DISTNAME=	mined-2000.7
PKGREVISION=	2
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
