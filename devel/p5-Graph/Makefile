# $NetBSD: Makefile,v 1.43 2023/12/16 12:08:47 mef Exp $

DISTNAME=	Graph-0.9727
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Graph
COMMENT=	Perl module for graph operations
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Graph/.packlist

DEPENDS+=	p5-Set-Object>=1.40:../../devel/p5-Set-Object
DEPENDS+=	p5-Heap>=0.80:../../devel/p5-Heap

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
