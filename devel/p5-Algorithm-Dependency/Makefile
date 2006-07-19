# $NetBSD: Makefile,v 1.7 2006/07/19 22:34:28 wiz Exp $

DISTNAME=	Algorithm-Dependency-1.102
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Dependency/
COMMENT=	Algorithmic framework for implementing dependency tree

DEPENDS+=	p5-Test-ClassAPI>=0.6:../../devel/p5-Test-ClassAPI
DEPENDS+=	p5-Params-Util>=0.07:../../devel/p5-Params-Util

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Algorithm/Dependency/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
