# $NetBSD: Makefile,v 1.2 2017/04/29 07:30:34 wen Exp $

DISTNAME=	XML-Compile-1.56
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARKOV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Compile/
COMMENT=	Perl module for compilation based XML processing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-LibXML>=2.0107:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-Log-Report>=1.03:../../devel/p5-Log-Report
DEPENDS+=	p5-Log-Report-Optional-[0-9]*:../../devel/p5-Log-Report-Optional
DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-XML-Compile-Tester>=0.90:../../textproc/p5-XML-Compile-Tester
BUILD_DEPENDS+=	p5-Test-Deep>=0.095:../../devel/p5-Test-Deep

PERL5_PACKLIST=	auto/XML/Compile/.packlist

REPLACE_PERL=	bin/xml2json bin/xml2yaml

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
