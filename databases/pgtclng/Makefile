# $NetBSD: Makefile,v 1.6 2008/03/13 17:38:48 joerg Exp $
#

VER=		1.5.3
DISTNAME=	pgtcl${VER}
PKGNAME=	pgtclng-${VER}
PKGREVISION=	3
CATEGORIES=	databases tcl
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1075/

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://pgtclng.projects.postgresql.org/
COMMENT=	Next Generation TCL interface to PostgreSQL

CONFLICTS+=	pgtcl-[0-9]*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-postgres-include=${PREFIX:Q}/include
CONFIGURE_ARGS+=	--with-postgres-lib=${PREFIX:Q}/lib

PGTCLLIBNAME		= libpgtcl${VER:C/\.//g}.so

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

post-install:
	cd ${PREFIX}/lib && ln -s pgtcl${VER}/${PGTCLLIBNAME} libpgtcl.so
