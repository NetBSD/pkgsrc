# $NetBSD: Makefile,v 1.7 2019/06/30 20:17:07 nia Exp $

DISTNAME=	XML-Compile-SOAP-3.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARKOV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Compile-SOAP
COMMENT=	SOAP 1.1 implementation for perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Report-[0-9]*:../../devel/p5-Log-Report
DEPENDS+=	p5-XML-Compile-[0-9]*:../../textproc/p5-XML-Compile
DEPENDS+=	p5-XML-Compile-Cache-[0-9]*:../../textproc/p5-XML-Compile-Cache
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-XML-Compile-Tester-[0-9]*:../../textproc/p5-XML-Compile-Tester

PERL5_PACKLIST=	auto/XML/Compile/SOAP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
