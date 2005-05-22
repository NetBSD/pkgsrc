# $NetBSD: Makefile,v 1.27 2005/05/22 20:08:13 jlam Exp $
#

DISTNAME=	calc-2.11.10.1
PKGNAME=	capc-${DISTNAME:S/t/./}
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
