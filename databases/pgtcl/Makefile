# $NetBSD: Makefile,v 1.13 2014/01/20 19:20:08 joerg Exp $
#

DISTNAME=	pgtcl1.5
PKGNAME=	pgtcl-1.5
PKGREVISION=	8
CATEGORIES=	databases tcl
CATEGORIES=	databases
MASTER_SITES=	ftp://gborg.postgresql.org/pub/pgtcl/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gborg.postgresql.org/project/pgtcl/projdisplay.php
COMMENT=	TCL interface to PostgreSQL

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	SHLIB_LD_FLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib

CPPFLAGS+=	-DUSE_INTERP_ERRORLINE

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
