# $NetBSD: Makefile,v 1.9 2003/09/27 17:07:35 grant Exp $
#

DISTNAME=	mined-2000.7
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	Html-aware editor

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK2=	yes

MAKEFILE=	makefile.bsd

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
