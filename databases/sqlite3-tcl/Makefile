# $NetBSD: Makefile,v 1.130 2026/01/10 17:04:27 adam Exp $

.include "../../databases/sqlite3/Makefile.common"

DISTNAME=	sqlite-autoconf-${SQLITE3_DISTVERSION}
PKGNAME=	sqlite3-tcl-${SQLITE3_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SQL Database Engine in a C Library (TCL extension)

WRKSRC=		${WRKDIR}/${DISTNAME}/tea

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
INSTALL_TARGET=		install-core

PLIST_SUBST+=		TCL_TRIM_DOTS=${PKGVERSION_NOREV:S/.//g}

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.6.10

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id \
	    ${PREFIX}/lib/tcl8.6/sqlite${PKGVERSION_NOREV}/libsqlite${PKGVERSION_NOREV}.dylib \
	    ${DESTDIR}${PREFIX}/lib/tcl8.6/sqlite${PKGVERSION_NOREV}/libsqlite${PKGVERSION_NOREV}.dylib
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
