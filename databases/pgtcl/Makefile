# $NetBSD: Makefile,v 1.10 2012/08/21 23:49:19 marino Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	SHLIB_LD_FLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
