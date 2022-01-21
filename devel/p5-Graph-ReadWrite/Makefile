# $NetBSD: Makefile,v 1.11 2022/01/21 01:57:36 wen Exp $

DISTNAME=	Graph-ReadWrite-2.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Graph-ReadWrite
COMMENT=	Perl module for reading and writing directed graphs
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Graph-[0-9]*:../../devel/p5-Graph
BUILD_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
BUILD_DEPENDS+=	p5-XML-Writer-[0-9]*:../../textproc/p5-XML-Writer
BUILD_DEPENDS+=	p5-Parse-Yapp-[0-9]*:../../devel/p5-Parse-Yapp

PERL5_PACKLIST=	auto/Graph/ReadWrite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
