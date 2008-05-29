# $NetBSD: Makefile,v 1.36 2008/05/29 17:56:35 drochner Exp $
#

DISTNAME=	calc-2.12.3.3
PKGNAME=	capc-${DISTNAME:S/t/./}
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		http://prdownloads.sourceforge.net/calc/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake
BUILD_TARGET=	calc-static-only
MAKE_ENV+=	BLD_TYPE=calc-static-only target=pkgsrc

TEST_TARGET=	check

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
