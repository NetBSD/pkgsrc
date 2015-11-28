# $NetBSD: Makefile,v 1.1 2015/11/28 07:33:38 wen Exp $

DISTNAME=		nlopt-2.4.2
CATEGORIES=		math
MASTER_SITES=		http://ab-initio.mit.edu/nlopt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ab-initio.mit.edu/nlopt/
COMMENT=		Nonlinear optimization library
LICENSE=		gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE=	lib/pkgconfig/nlopt.pc

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
