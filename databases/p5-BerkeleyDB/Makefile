# $NetBSD: Makefile,v 1.5 2004/08/04 05:44:12 jlam Exp $
#

DISTNAME=	BerkeleyDB-0.25
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bdb
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BerkeleyDB/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/BerkeleyDB/
COMMENT=	Access Berkeley DB

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_REQD+=		5.6.0
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/BerkeleyDB/.packlist

MAKE_ENV+=	BERKELEYDB_INCLUDE="${BDBBASE}/include"
MAKE_ENV+=	BERKELEYDB_LIB="${BDBBASE}/lib"
MAKE_ENV+=	BERKELEYDB_NAME="${BUILDLINK_LIBS.bdb}"

.include "../../mk/bdb.buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
