# $NetBSD: Makefile,v 1.7 2003/07/17 21:34:40 grant Exp $
#

DISTNAME=	mined-2000.7
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	html-aware editor

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK2=	yes

MAKEFILE=	makefile.bsd

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
