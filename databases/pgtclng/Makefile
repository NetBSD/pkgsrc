# $NetBSD: Makefile,v 1.9 2011/02/28 14:52:43 wiz Exp $
#

VER=		1.5.3
DISTNAME=	pgtcl${VER}
PKGNAME=	pgtclng-${VER}
PKGREVISION=	4
CATEGORIES=	databases tcl
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1075/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pgtclng.projects.postgresql.org/
COMMENT=	Next Generation TCL interface to PostgreSQL

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	pgtcl-[0-9]*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-postgres-include=${PREFIX:Q}/include
CONFIGURE_ARGS+=	--with-postgres-lib=${PREFIX:Q}/lib

PGTCLLIBNAME		= libpgtcl${VER:C/\.//g}.so

post-install:
	cd ${DESTDIR}${PREFIX}/lib && ln -s pgtcl${VER}/${PGTCLLIBNAME} libpgtcl.so

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
