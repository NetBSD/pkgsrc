# $NetBSD: Makefile,v 1.12 2007/01/04 22:38:49 adam Exp $

DISTNAME=	glpk-4.13
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gnu.org/gnu/glpk/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/glpk/glpk.html
COMMENT=	Library for solving linear programming problems

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
