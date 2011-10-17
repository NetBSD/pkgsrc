# $NetBSD: Makefile,v 1.1.1.1 2011/10/17 08:44:32 obache Exp $
#

.include "../../databases/gdbm/Makefile.common"

PKGNAME=	${DISTNAME:S/-/_compat-/}

COMMENT+=	dbm and ndbm compat library

DEPENDS+=	gdbm-${PKGVERSION_NOREV}{,nb[0-9]*}:../../databases/gdbm

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFIGURE_ARGS+=	--enable-libgdbm-compat

BUILD_DIRS=		compat

.include "../../mk/bsd.pkg.mk"
