# $NetBSD: Makefile,v 1.72 2022/03/07 22:59:49 wiz Exp $

DISTNAME=	g-wrap-1.9.15
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/g-wrap/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/g-wrap/
COMMENT=	Tool for generating guile wrappers for C code

LICENSE=	gnu-lgpl-v2.1

# standard.c ends up malformed with MAKE_JOBS=4
MAKE_JOBS_SAFE=	no

DEPENDS+=	guile-lib>=0.1.2:../../devel/guile-lib

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake makeinfo pkg-config
USE_LIBTOOL=		YES
TEST_TARGET=		check
INFO_FILES=		YES

INSTALLATION_DIRS=	share/guile/site/g-wrap/guile/ws

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "SunOS" || !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--disable-Werror
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
