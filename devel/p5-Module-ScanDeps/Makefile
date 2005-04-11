# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:33 tv Exp $
#

DISTNAME=	Module-ScanDeps-0.51
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5msd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-ScanDeps/
COMMENT=	Perl 5 module to recursively scan Perl code for dependencies

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Module/ScanDeps/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
