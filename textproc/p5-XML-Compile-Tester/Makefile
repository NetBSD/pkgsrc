# $NetBSD: Makefile,v 1.7 2019/08/11 13:23:52 wiz Exp $

DISTNAME=	XML-Compile-Tester-0.91
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARKOV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Compile-Tester
COMMENT=	Perl module for testing compilation based XML processing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Report-[0-9]*:../../devel/p5-Log-Report
DEPENDS+=	p5-Log-Report-Optional-[0-9]*:../../devel/p5-Log-Report-Optional
DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction

PERL5_PACKLIST=	auto/XML/Compile/Tester/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
