# $NetBSD: Makefile,v 1.36 2026/01/18 09:11:42 wiz Exp $

DISTNAME=	DBIx-DataSource-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	19
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/DBIx::DataSource
COMMENT=	Create and drop functions for databases

PERL5_PACKLIST=		auto/DBIx/DataSource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
