# $NetBSD: Makefile,v 1.14 2011/08/07 05:44:09 adam Exp $

DISTNAME=	Algorithm-Dependency-1.110
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Dependency/
COMMENT=	Algorithmic framework for implementing dependency tree
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-ClassAPI>=0.6:../../devel/p5-Test-ClassAPI
DEPENDS+=	p5-Params-Util>=0.31:../../devel/p5-Params-Util

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Algorithm/Dependency/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
