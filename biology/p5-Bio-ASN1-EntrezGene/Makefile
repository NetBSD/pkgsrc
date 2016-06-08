# $NetBSD: Makefile,v 1.4 2016/06/08 19:22:16 wiz Exp $

DISTNAME=	Bio-ASN1-EntrezGene-1.70
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	biology perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Bio-ASN1-EntrezGene
COMMENT=	Regular expression-based Perl Parser for NCBI Entrez Gene
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Bio/ASN1/EntrezGene/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
