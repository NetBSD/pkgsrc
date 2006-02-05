# $NetBSD: Makefile,v 1.41 2006/02/05 23:08:42 joerg Exp $

DISTNAME=	g-wrap-1.9.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/g-wrap/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/g-wrap/
COMMENT=	Tool for generating guile wrappers for C code

DEPENDS+=	guile-lib>=0.1.2:../../devel/guile-lib


GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES
TEST_TARGET=		check

USE_MAKEINFO=		YES
INFO_FILES=		g-wrap.info

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/guile/site/g-wrap/guile/ws

.include "../../devel/glib/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
