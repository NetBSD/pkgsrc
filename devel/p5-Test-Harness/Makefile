# $NetBSD: Makefile,v 1.25 2006/08/06 15:00:07 adrianp Exp $
#

DISTNAME=	Test-Harness-2.62
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/P/PE/PETDANCE/
COMMENT=	Run Perl standard test scripts with statistics

PERL5_PACKLIST= auto/Test/Harness/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
