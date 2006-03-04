# $NetBSD: Makefile,v 1.10 2006/03/04 21:29:21 jlam Exp $

DISTNAME=	Graph-0.201
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for graph operations

DEPENDS+=		p5-Heap>=0.50:../../devel/p5-Heap

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
