# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 15:10:11 is Exp $
#

VER=		1.5.3
VERNODOT=	153
DISTNAME=	pgtcl${VER}
PKGNAME=	pgtclng-${VER}
PKGREVISION=	0
CATEGORIES=	databases tcl
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1075/

CONFLICTS+=	pgtcl-[0-9]*

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://pgtclng.projects.postgresql.org/
COMMENT=	Next Generation TCL interface to PostgreSQL

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-postgres-include=${PREFIX:Q}/include 
CONFIGURE_ARGS+=	--with-postgres-lib=${PREFIX:Q}/lib 

PGTCLLIBNAME		= libpgtcl${VERNODOT}.so

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

post-install:
		${LN} -s ${PREFIX:Q}/lib/pgtcl-${VER}/${PGTCLLIBNAME} \
			${PREFIX:Q}/lib/libpgtcl.so
