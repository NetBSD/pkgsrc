# $NetBSD: Makefile,v 1.16 2003/07/17 21:47:23 grant Exp $
#

DISTNAME=	calc-2.11.7
PKGNAME=	capc-${DISTNAME:S/t/./}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		http://prdownloads.sourceforge.net/calc/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

USE_BUILDLINK2=	# defined

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
