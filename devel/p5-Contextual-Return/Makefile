# $NetBSD: Makefile,v 1.11 2013/12/12 06:52:14 wen Exp $

DISTNAME=	Contextual-Return-0.004007
PKGNAME=	p5-${DISTNAME:S/004007/004.007/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Contextual-Return/
COMMENT=	Perl 5 module to create context-senstive return values
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10.0,p5-version-[0-9]*}:../../devel/p5-version
DEPENDS+=	p5-Want-[0-9]*:../../devel/p5-Want

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Contextual/Return/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
