# $NetBSD: Makefile,v 1.14 2005/12/05 20:49:58 rillig Exp $
#

DISTNAME=	BerkeleyDB-0.26
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bdb
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BerkeleyDB/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/BerkeleyDB/
COMMENT=	Access Berkeley DB

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BDB_ACCEPTED=		db4 db3 db2
PERL5_PACKLIST=		auto/BerkeleyDB/.packlist

MAKE_ENV+=	BERKELEYDB_INCLUDE="${BDBBASE}/include/${BDB_TYPE}"
MAKE_ENV+=	BERKELEYDB_LIB="${BDBBASE}/lib"
MAKE_ENV+=	BERKELEYDB_NAME=${BDB_LIBS:Q}

.include "../../mk/bdb.buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
