# $NetBSD: Makefile,v 1.11 2012/10/02 21:25:38 asau Exp $
#

DISTNAME=	pgtcl1.5
PKGNAME=	pgtcl-1.5
PKGREVISION=	7
CATEGORIES=	databases tcl
CATEGORIES=	databases
MASTER_SITES=	ftp://gborg.postgresql.org/pub/pgtcl/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gborg.postgresql.org/project/pgtcl/projdisplay.php
COMMENT=	TCL interface to PostgreSQL

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	SHLIB_LD_FLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
