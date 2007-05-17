# $NetBSD: Makefile,v 1.49 2007/05/17 23:59:34 gdt Exp $

DISTNAME=	g-wrap-1.9.8
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/g-wrap/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/g-wrap/
COMMENT=	Tool for generating guile wrappers for C code

# not sure
MAKE_JOBS_SAFE=	no

DEPENDS+=	guile-lib>=0.1.2:../../devel/guile-lib

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake makeinfo pkg-config
USE_LIBTOOL=		YES
TEST_TARGET=		check
INFO_FILES=		YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/guile/site/g-wrap/guile/ws

.include "../../devel/glib2/buildlink3.mk"
# wrong version
#.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
