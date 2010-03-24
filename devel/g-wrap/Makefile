# $NetBSD: Makefile,v 1.57 2010/03/24 19:43:22 asau Exp $

DISTNAME=	g-wrap-1.9.12
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/g-wrap/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/g-wrap/
COMMENT=	Tool for generating guile wrappers for C code

PKG_DESTDIR_SUPPORT=	user-destdir

# not sure
MAKE_JOBS_SAFE=	no

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
