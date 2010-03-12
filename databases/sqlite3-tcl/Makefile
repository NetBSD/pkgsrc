# $NetBSD: Makefile,v 1.15 2010/03/12 09:11:27 adam Exp $

DISTNAME=	sqlite-3_6_23-tea
PKGNAME=	${DISTNAME:S/sqlite/sqlite3-tcl/:S/-tea//:S/_/./g}
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/ \
		http://www.sqlite.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sqlite.org/
COMMENT=	SQL Database Engine in a C Library (TCL extension)
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

PLIST_SUBST+=		TCL_TRIM_DOTS=${PKGVERSION_NOREV:S/.//g}

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.6.10

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
