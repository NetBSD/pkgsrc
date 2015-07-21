# $NetBSD: Makefile,v 1.1 2015/07/21 17:25:10 gson Exp $

DISTNAME=	Graph-ReadWrite-2.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~neilb/Graph-ReadWrite/
COMMENT=	Perl module for reading and writing directed graphs
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Graph/ReadWrite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
