# $NetBSD: Makefile,v 1.45 2015/08/17 17:11:25 wiz Exp $
#

DISTNAME=	calc-2.12.4.13
PKGNAME=	capc-${DISTNAME:S/t/./}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=calc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake
BUILD_TARGET=	calc-static-only
MAKE_ENV+=	BLD_TYPE=calc-static-only target=pkgsrc
MAKE_ENV+=	DEBUG=${CFLAGS:M*:Q}

INSTALL_MAKE_FLAGS+=	T=${DESTDIR}

TEST_TARGET=	check

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
