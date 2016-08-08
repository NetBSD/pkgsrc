# $NetBSD: Makefile,v 1.4 2016/08/08 05:28:42 mef Exp $

DISTNAME=	Graph-ReadWrite-2.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~neilb/Graph-ReadWrite/
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
