# $NetBSD: Makefile,v 1.10 2003/09/28 09:13:56 jlam Exp $
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

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
