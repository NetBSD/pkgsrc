# $NetBSD: Makefile,v 1.3 2003/06/02 01:20:30 jschauma Exp $

DISTNAME=	Graph-0.201
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl module for graph operations

DEPENDS+=		p5-Heap>=0.50:../../devel/p5-Heap

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
