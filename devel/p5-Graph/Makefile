# $NetBSD: Makefile,v 1.12 2008/06/20 01:09:16 joerg Exp $

DISTNAME=	Graph-0.80
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for graph operations

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Heap>=0.50:../../devel/p5-Heap

PERL5_PACKLIST=		auto/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
