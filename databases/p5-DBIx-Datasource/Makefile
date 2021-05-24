# $NetBSD: Makefile,v 1.31 2021/05/24 19:49:37 wiz Exp $
#

DISTNAME=	DBIx-DataSource-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.420.am/dbix-datasource/
COMMENT=	Create and drop functions for databases

PERL5_PACKLIST=		auto/DBIx/DataSource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
