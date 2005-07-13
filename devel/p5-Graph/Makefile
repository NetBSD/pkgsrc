# $NetBSD: Makefile,v 1.8 2005/07/13 18:01:25 jlam Exp $

DISTNAME=	Graph-0.201
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for graph operations

DEPENDS+=		p5-Heap>=0.50:../../devel/p5-Heap

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
