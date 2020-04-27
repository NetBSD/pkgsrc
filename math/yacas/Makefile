# $NetBSD: Makefile,v 1.41 2020/04/27 17:46:28 rillig Exp $
#

DISTNAME=	yacas-1.2.2
PKGREVISION=	7
CATEGORIES=	math
MASTER_SITES=	http://yacas.sourceforge.net/backups/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yacas.sourceforge.net/
COMMENT=	Yet Another Computer Algebra System
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl

TEST_TARGET=	test

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/yacas

REPLACE_PERL=	manmake/txt2yacasdoc.pl

.include "../../math/gsl/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
