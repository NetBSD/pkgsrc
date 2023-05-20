# $NetBSD: Makefile,v 1.20 2023/05/20 07:43:48 wiz Exp $

DISTNAME=	Term-Table-0.016
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Term::Table
COMMENT=	Format a header and rows into a table
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Importer-[0-9]*:../../devel/p5-Importer

PERL5_PACKLIST=	auto/Term/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
