# $NetBSD: Makefile,v 1.1.1.1 2011/02/16 06:33:11 manu Exp $

PKGNAME=	postgresql90-fuzzystrmatch-${BASE_VERS}
COMMENT=	PostgreSQL fuzzystrmatch contribution

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql90/Makefile.common"

INSTALL_DIRS+=	contrib/fuzzystrmatch

BUILD_DIRS=	${INSTALL_DIRS}

USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
