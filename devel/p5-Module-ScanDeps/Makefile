# $NetBSD: Makefile,v 1.10 2007/06/09 23:37:46 abs Exp $
#

DISTNAME=	Module-ScanDeps-0.74
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5msd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-ScanDeps/
COMMENT=	Perl 5 module to recursively scan Perl code for dependencies

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/ScanDeps/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
