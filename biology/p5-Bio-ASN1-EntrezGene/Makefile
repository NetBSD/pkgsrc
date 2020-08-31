# $NetBSD: Makefile,v 1.10 2020/08/31 18:06:39 wiz Exp $

DISTNAME=	Bio-ASN1-EntrezGene-1.72
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	biology perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Bio-ASN1-EntrezGene
COMMENT=	Regular expression-based Perl Parser for NCBI Entrez Gene
LICENSE=	${PERL5_LICENSE}

# needed for tests, but would introduce dependency cycle
#BUILD_DEPENDS+=	bioperl-[0-9]*:../../biology/bioperl

PERL5_PACKLIST=	auto/Bio/ASN1/EntrezGene/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
