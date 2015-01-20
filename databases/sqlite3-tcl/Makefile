# $NetBSD: Makefile,v 1.69 2015/01/20 20:11:07 adam Exp $

DISTNAME=	sqlite-autoconf-3080801
PKGNAME=	sqlite3-tcl-3.8.8.1
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/2015/ \
		http://www.sqlite.org/2015/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sqlite.org/
COMMENT=	SQL Database Engine in a C Library (TCL extension)
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/${DISTNAME}/tea

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

PLIST_SUBST+=		TCL_TRIM_DOTS=${PKGVERSION_NOREV:S/.//g}

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.6.10

# avoid conflict with lang/tcl
post-extract:
	mv ${WRKSRC}/doc/sqlite3.n ${WRKSRC}/doc/sqlite3-tcl.n

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
