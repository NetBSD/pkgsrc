# $NetBSD: Makefile,v 1.59 2011/12/05 03:34:10 gdt Exp $

DISTNAME=	g-wrap-1.9.14
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/g-wrap/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/g-wrap/
COMMENT=	Tool for generating guile wrappers for C code

PKG_DESTDIR_SUPPORT=	user-destdir

# not sure
#MAKE_JOBS_SAFE=	no

DEPENDS+=	guile-lib>=0.1.2:../../devel/guile-lib

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake makeinfo pkg-config
USE_LIBTOOL=		YES
TEST_TARGET=		check
INFO_FILES=		YES

INSTALLATION_DIRS=	share/guile/site/g-wrap/guile/ws

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
