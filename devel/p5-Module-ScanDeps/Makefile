# $NetBSD: Makefile,v 1.2 2004/12/20 11:31:01 grant Exp $
#

DISTNAME=	Module-ScanDeps-0.50
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5msd
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-ScanDeps/
COMMENT=	Perl 5 module to recursively scan Perl code for dependencies

USE_BUILDLINK3=	YES
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Module/ScanDeps/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
