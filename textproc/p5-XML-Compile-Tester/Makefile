# $NetBSD: Makefile,v 1.3 2017/06/05 14:24:55 ryoon Exp $

DISTNAME=	XML-Compile-Tester-0.90
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARKOV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Compile-Tester/
COMMENT=	Perl module for testing compilation based XML processing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Report-[0-9]*:../../devel/p5-Log-Report
DEPENDS+=	p5-Log-Report-Optional-[0-9]*:../../devel/p5-Log-Report-Optional
DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction

PERL5_PACKLIST=	auto/XML/Compile/Tester/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
