# $NetBSD: Makefile,v 1.6 2003/07/13 13:51:34 wiz Exp $
#

DISTNAME=	mined-2000.7
PKGREVISION=	1
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
