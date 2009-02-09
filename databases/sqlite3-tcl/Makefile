# $NetBSD: Makefile,v 1.9 2009/02/09 16:44:35 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/sqlite3/Makefile.common"

PKGNAME:=		${PKGNAME:S/-/-tcl-/}

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

BUILD_TARGET=		libtclsqlite3.la
INSTALL_TARGET=		tcl_install
TEST_TARGET=		test

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.6.10

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
