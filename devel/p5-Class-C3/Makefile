# $NetBSD: Makefile,v 1.35 2022/06/28 11:32:00 wiz Exp $

DISTNAME=	Class-C3-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-C3
COMMENT=	Pragma to use the C3 method resolution order algortihm
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Algorithm-C3-[0-9]*:../../devel/p5-Algorithm-C3

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Class/C3/.packlist

# As the minimum required version by pkgsrc for Perl 5 is 5.10, this
# package for the Perl 5 module Class::C3 does not need any dependency:
# it is only a stub for the CORE module mro, available since Perl
# version 5.9.5

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
