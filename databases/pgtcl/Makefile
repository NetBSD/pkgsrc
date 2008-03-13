# $NetBSD: Makefile,v 1.4 2008/03/13 17:38:48 joerg Exp $
#

DISTNAME=	pgtcl1.5
PKGNAME=	pgtcl-1.5
PKGREVISION=	3
CATEGORIES=	databases tcl
CATEGORIES=	databases
MASTER_SITES=	ftp://gborg.postgresql.org/pub/pgtcl/stable/

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://gborg.postgresql.org/project/pgtcl/projdisplay.php
COMMENT=	TCL interface to PostgreSQL

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
