# $NetBSD: Makefile,v 1.2 2020/07/13 19:45:45 alnsn Exp $
#

DISTNAME=	fplll-5.3.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=fplll/}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION}//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://perso.ens-lyon.fr/damien.stehle/\#software
COMMENT=	Lattice algorithms using floating-point arithmetic
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake autoconf automake
USE_LANGUAGES=	c c++

TEST_TARGET=	check

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=2.0.3
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
