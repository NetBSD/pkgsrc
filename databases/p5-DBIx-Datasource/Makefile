# $NetBSD: Makefile,v 1.34 2024/11/16 12:03:27 wiz Exp $
#

DISTNAME=	DBIx-DataSource-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	18
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.420.am/dbix-datasource/
COMMENT=	Create and drop functions for databases

PERL5_PACKLIST=		auto/DBIx/DataSource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
