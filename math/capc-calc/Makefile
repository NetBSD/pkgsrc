# $NetBSD: Makefile,v 1.24 2004/10/03 00:12:55 tv Exp $
#

DISTNAME=	calc-2.11.10
PKGNAME=	capc-${DISTNAME:S/t/./}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		http://prdownloads.sourceforge.net/calc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
