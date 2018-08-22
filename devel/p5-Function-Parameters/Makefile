# $NetBSD: Makefile,v 1.8 2018/08/22 09:44:04 wiz Exp $

DISTNAME=	Function-Parameters-2.001003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MAUKE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Function-Parameters/
COMMENT=	Perl5 subroutine definitions with parameter lists
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Dir-Self-[0-9]*:../../devel/p5-Dir-Self

PERL5_PACKLIST=	auto/Function/Parameters/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
