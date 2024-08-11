# $NetBSD: Makefile,v 1.23 2024/08/11 06:19:40 wiz Exp $

DISTNAME=	Term-Table-0.022
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Term::Table
COMMENT=	Format a header and rows into a table
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Term/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
