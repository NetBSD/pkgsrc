# $NetBSD: Makefile,v 1.5 2019/11/03 19:24:34 rillig Exp $

PKGNAME=	suse_sqlite3-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libsqlite3-0-3.7.17-2.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for sqlite3

EMUL_MODULES.linux=	base

PLIST_SRC=	${RPM2PKG_PLIST}

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
