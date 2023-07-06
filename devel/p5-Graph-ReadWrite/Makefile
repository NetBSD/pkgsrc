# $NetBSD: Makefile,v 1.14 2023/07/06 09:39:17 wiz Exp $

DISTNAME=	Graph-ReadWrite-2.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Graph-ReadWrite
COMMENT=	Perl module for reading and writing directed graphs
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-Graph-[0-9]*:../../devel/p5-Graph
TOOL_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
TOOL_DEPENDS+=	p5-XML-Writer-[0-9]*:../../textproc/p5-XML-Writer
TOOL_DEPENDS+=	p5-Parse-Yapp-[0-9]*:../../devel/p5-Parse-Yapp

PERL5_PACKLIST=	auto/Graph/ReadWrite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
