# $NetBSD: Makefile,v 1.18 2023/04/19 13:11:49 joerg Exp $

DISTNAME=	pgtcl1.5
PKGNAME=	pgtcl-1.5
PKGREVISION=	9
CATEGORIES=	databases tcl
MASTER_SITES=	# ftp://gborg.postgresql.org/pub/pgtcl/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://gborg.postgresql.org/project/pgtcl/projdisplay.php
COMMENT=	TCL interface to PostgreSQL

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	SHLIB_LD_FLAGS=${LDFLAGS:Q}

CPPFLAGS+=	-DUSE_INTERP_ERRORLINE

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
