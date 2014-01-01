# $NetBSD: Makefile,v 1.4 2014/01/01 09:20:33 wen Exp $
#

DISTNAME=	Import-Into-1.002000
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Import-Into/
COMMENT=	Perl5 module to import packages into other packages
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Import/Into/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
