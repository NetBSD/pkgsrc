# $NetBSD: Makefile,v 1.20 2008/06/20 01:09:24 joerg Exp $

DISTNAME=	glpk-4.28
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
