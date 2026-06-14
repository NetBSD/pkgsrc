# $NetBSD: Makefile,v 1.49 2026/06/14 17:45:05 nia Exp $

DISTNAME=	glpk-5.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=glpk/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/glpk/glpk.html
COMMENT=	Library for solving linear programming problems
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gmp
TEST_TARGET=		check

# defines its own bool type which conflicts with the C23 keyword
FORCE_C_STD=		gnu89

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
