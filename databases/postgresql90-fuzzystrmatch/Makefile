# $NetBSD: Makefile,v 1.2 2011/02/16 12:22:00 wiz Exp $

PKGNAME=        ${DISTNAME:C/-/90-fuzzystrmatch-/}
COMMENT=	PostgreSQL fuzzystrmatch contribution

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql90/Makefile.common"

INSTALL_DIRS+=	contrib/fuzzystrmatch

BUILD_DIRS=	${INSTALL_DIRS}

USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
