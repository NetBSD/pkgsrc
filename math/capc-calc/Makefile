# $NetBSD: Makefile,v 1.29 2006/03/04 21:30:03 jlam Exp $
#

DISTNAME=	calc-2.11.10.1
PKGNAME=	capc-${DISTNAME:S/t/./}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		http://prdownloads.sourceforge.net/calc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

USE_TOOLS+=	gmake

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
