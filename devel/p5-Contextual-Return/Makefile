# $NetBSD: Makefile,v 1.26 2021/05/24 19:50:23 wiz Exp $

DISTNAME=	Contextual-Return-0.004014
# insert dot between each 3 digits
PKGNAME=	p5-${DISTNAME:C/([0-9][0-9][0-9])([0-9][0-9][0-9])/\1.\2/}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Contextual-Return
COMMENT=	Perl 5 module to create context-senstive return values
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10.0,p5-version-[0-9]*}:../../devel/p5-version
DEPENDS+=	p5-Want-[0-9]*:../../devel/p5-Want

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Contextual/Return/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
