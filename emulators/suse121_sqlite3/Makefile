# $NetBSD: Makefile,v 1.4 2015/02/16 10:15:46 jperkin Exp $

PKGNAME=	suse_sqlite3-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libsqlite3-0-3.7.8-1.1.2.${SUSE_ARCH}

MAINTAINER=	rodent@NetBSD.org
COMMENT=	Linux compatibility package for sqlite3

EMUL_MODULES.linux=	base

PLIST_SRC=	${RPM2PKG_PLIST}

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
