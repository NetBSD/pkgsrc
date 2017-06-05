# $NetBSD: Makefile,v 1.4 2017/06/05 14:23:40 ryoon Exp $

DISTNAME=	Term-Table-0.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/E/EX/EXODIST/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/E/EX/EXODIST/
COMMENT=	Format a header and rows into a table
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Importer-[0-9]*:../../devel/p5-Importer

PERL5_PACKLIST=	auto/Term/Table/.packlist


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
