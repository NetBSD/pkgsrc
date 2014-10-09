# $NetBSD: Makefile,v 1.7 2014/10/09 14:06:21 wiz Exp $
#

DISTNAME=	Import-Into-1.002004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Import-Into/
COMMENT=	Perl5 module to import packages into other packages
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Import/Into/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
