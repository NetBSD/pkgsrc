# $NetBSD: Makefile,v 1.1.1.1 2007/07/29 11:45:15 adrianp Exp $

DISTNAME=		Return-Value-1.302
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RJ/RJBS/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		http://search.cpan.org/dist/Return-Value/
COMMENT=		Polymorphic Return Values

DEPENDS+=		{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Return/Value/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
