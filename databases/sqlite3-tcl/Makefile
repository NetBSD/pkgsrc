# $NetBSD: Makefile,v 1.2 2005/09/30 12:17:39 wiz Exp $

.include "../../databases/sqlite3/Makefile.common"

PKGNAME:=		${PKGNAME:S/-/-tcl-/}

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

BUILD_TARGET=		libtclsqlite3.la
INSTALL_TARGET=		tcl_install
TEST_TARGET=		test

BUILDLINK_DEPENDS.sqlite3+=	sqlite3>=3.2.7

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
