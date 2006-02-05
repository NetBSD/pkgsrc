# $NetBSD: Makefile,v 1.28 2006/02/05 23:10:01 joerg Exp $
#

DISTNAME=	calc-2.11.10.1
PKGNAME=	capc-${DISTNAME:S/t/./}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		http://prdownloads.sourceforge.net/calc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

USE_TOOLS+=	gmake

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
