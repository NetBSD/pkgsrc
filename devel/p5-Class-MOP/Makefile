# $NetBSD: Makefile,v 1.1.1.1 2008/07/26 12:21:38 seb Exp $
#

DISTNAME=	Class-MOP-0.63
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-MOP/
COMMENT=	Perl 5 module providing a meta object protocol

DEPENDS+=	p5-Sub-Identify>=0.03:../../devel/p5-Sub-Identify
DEPENDS+=	p5-Sub-Name>=0.02:../../devel/p5-Sub-Name
DEPENDS+=	p5-MRO-Compat>=0.05:../../devel/p5-MRO-Compat

# Only for test target
# Test::More
#BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
#BUILD_DEPENDS+=	p5-PathTools-[0-9]*:../../devel/p5-PathTools

PERL5_PACKLIST=	auto/Class/MOP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
