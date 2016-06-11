# $NetBSD: Makefile,v 1.1 2016/06/11 12:44:27 kamil Exp $

DISTNAME=	Function-Parameters-1.0705
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MAUKE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Function-Parameters/
COMMENT=	Perl5 subroutine definitions with parameter lists
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

PERL5_PACKLIST=	auto/Function/Parameters/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
