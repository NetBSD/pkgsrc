# $NetBSD: Makefile,v 1.4 2004/06/08 16:38:58 mjl Exp $
#

DISTNAME=	BerkeleyDB-0.25
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bdb
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BerkeleyDB/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/BerkeleyDB/
COMMENT=	Access Berkeley DB

DEPENDS+=	db3-[0-9]*:../db3

MAKE_ENV+= BERKELEYDB_NAME=-ldb3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_REQD+=		5.6.0
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/BerkeleyDB/.packlist

.include "../db3/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
