# $NetBSD: Makefile,v 1.31 2011/12/07 18:52:22 drochner Exp $

DISTNAME=	glpk-4.47
CATEGORIES=	math
MASTER_SITES=	$(MASTER_SITE_GNU:=glpk/)

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/glpk/glpk.html
COMMENT=	Library for solving linear programming problems

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gmp
TEST_TARGET=		check

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
