# $NetBSD: Makefile,v 1.11 2002/10/25 18:38:41 wiz Exp $
#

DISTNAME=	calc-2.11.4t2
PKGNAME=	capc-${DISTNAME:S/t/./}
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		ftp://ftp.batnet.com/wombats/noll/ftp/pub/calc/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

USE_BUILDLINK2=	# defined

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
