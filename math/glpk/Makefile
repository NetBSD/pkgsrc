# $NetBSD: Makefile,v 1.22 2008/09/08 07:15:01 adam Exp $

DISTNAME=	glpk-4.31
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
