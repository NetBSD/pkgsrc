# $NetBSD: Makefile,v 1.4 2017/06/05 14:23:02 ryoon Exp $

DISTNAME=	Function-Parameters-2.000006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MAUKE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Function-Parameters/
COMMENT=	Perl5 subroutine definitions with parameter lists
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
# for make test
BUILD_DEPENDS+=	p5-Dir-Self-[0-9]*:../../devel/p5-Dir-Self

PERL5_PACKLIST=	auto/Function/Parameters/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
