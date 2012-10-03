# $NetBSD: Makefile,v 1.22 2012/10/03 21:55:05 wiz Exp $

DISTNAME=	Graph-0.94
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Graph/
COMMENT=	Perl module for graph operations
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
