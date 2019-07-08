# $NetBSD: Makefile,v 1.46 2019/07/08 16:28:16 leot Exp $

DISTNAME=	glpk-4.65
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=glpk/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/glpk/glpk.html
COMMENT=	Library for solving linear programming problems
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gmp
TEST_TARGET=		check

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
