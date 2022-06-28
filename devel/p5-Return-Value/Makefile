# $NetBSD: Makefile,v 1.23 2022/06/28 11:33:10 wiz Exp $

DISTNAME=		Return-Value-1.666005
# put dot in the center of 6 digits      1.666005       -> 1.666.005
PKGNAME=		p5-${DISTNAME:C/([0-9][0-9][0-9])([0-9][0-9][0-9])/\1.\2/}
PKGREVISION=		6
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RJ/RJBS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Return-Value
COMMENT=		Polymorphic Return Values
LICENSE=		${PERL5_LICENSE}

#DEPENDS+=		{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Return/Value/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
