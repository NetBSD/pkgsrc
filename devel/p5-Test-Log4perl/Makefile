# $NetBSD: Makefile,v 1.19 2022/06/28 11:33:26 wiz Exp $
#

DISTNAME=	Test-Log4perl-0.1001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Log4perl
COMMENT=	Perl 5 module to test Log::Log4perl

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Log4perl/.packlist

DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained
DEPENDS+=	p5-Lingua-EN-Numbers-Ordinate-[0-9]*:../../textproc/p5-Lingua-EN-Numbers-Ordinate
DEPENDS+=	p5-Log-Log4perl-[0-9]*:../../devel/p5-Log-Log4perl
DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
