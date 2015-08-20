# $NetBSD: Makefile,v 1.3 2015/08/20 14:01:42 mef Exp $

DISTNAME=	ExtUtils-MakeMaker-CPANfile-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IS/ISHIGAKI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~ishigaki/ExtUtils-MakeMaker-CPANfile/
COMMENT=	Loads CPANfile & modifies parameters for WriteMakefile (Makefile.PL)
LICENSE=	${PERL5_LICENSE}

#for make test
BUILD_DEPENDS+=	p5-Module-CPANfile-[0-9]*:../../devel/p5-Module-CPANfile

PERL5_PACKLIST=	auto/ExtUtils/MakeMaker/CPANfile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
