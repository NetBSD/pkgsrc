# $NetBSD: Makefile,v 1.5 2018/08/22 09:47:05 wiz Exp $

DISTNAME=	XML-Compile-Tester-0.91
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
