# $NetBSD: Makefile,v 1.12 2003/01/03 20:35:29 wiz Exp $
#

DISTNAME=	calc-2.11.6
PKGNAME=	capc-${DISTNAME:S/t/./}
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		http://prdownloads.sourceforge.net/calc/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

USE_BUILDLINK2=	# defined

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
