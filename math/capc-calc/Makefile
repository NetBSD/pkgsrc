# $NetBSD: Makefile,v 1.20 2004/03/10 18:17:11 wiz Exp $
#

DISTNAME=	calc-2.11.9.2
PKGNAME=	capc-${DISTNAME:S/t/./}
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		http://prdownloads.sourceforge.net/calc/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

USE_BUILDLINK3=	# defined

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
