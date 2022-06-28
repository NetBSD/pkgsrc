# $NetBSD: Makefile,v 1.13 2022/06/28 11:31:01 wiz Exp $

DISTNAME=	Bio-ASN1-EntrezGene-1.73
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	biology perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Bio-ASN1-EntrezGene
COMMENT=	Regular expression-based Perl Parser for NCBI Entrez Gene
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
# needed for tests, but would introduce dependency cycle
#TEST_DEPENDS+=	bioperl-[0-9]*:../../biology/bioperl

PERL5_PACKLIST=	auto/Bio/ASN1/EntrezGene/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
