# $NetBSD: Makefile,v 1.25 2008/12/19 19:47:38 adam Exp $

DISTNAME=	glpk-4.34
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gnu.org/gnu/glpk/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/glpk/glpk.html
COMMENT=	Library for solving linear programming problems

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
