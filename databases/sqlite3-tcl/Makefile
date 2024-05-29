# $NetBSD: Makefile,v 1.119 2024/05/29 16:31:54 adam Exp $

PKGREVISION= 1
.include "../../databases/sqlite3/Makefile.common"

DISTNAME=	sqlite-autoconf-${SQLITE3_DISTVERSION}
PKGNAME=	sqlite3-tcl-${SQLITE3_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SQL Database Engine in a C Library (TCL extension)

WRKSRC=		${WRKDIR}/${DISTNAME}/tea

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

PLIST_SUBST+=		TCL_TRIM_DOTS=${PKGVERSION_NOREV:S/.//g}

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.6.10

# avoid conflict with lang/tcl
post-extract:
	${MV} ${WRKSRC}/doc/sqlite3.n ${WRKSRC}/doc/sqlite3-tcl.n

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id \
	    ${PREFIX}/lib/sqlite3/libsqlite${PKGVERSION_NOREV}.dylib \
	    ${DESTDIR}${PREFIX}/lib/sqlite3/libsqlite${PKGVERSION_NOREV}.dylib
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
