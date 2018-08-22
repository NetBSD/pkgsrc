# $NetBSD: Makefile,v 1.24 2018/08/22 09:43:34 wiz Exp $

DISTNAME=	Algorithm-Dependency-1.110
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Dependency/
COMMENT=	Algorithmic framework for implementing dependency tree
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-ClassAPI>=0.6:../../devel/p5-Test-ClassAPI
DEPENDS+=	p5-Params-Util>=0.31:../../devel/p5-Params-Util

PERL5_PACKLIST=		auto/Algorithm/Dependency/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
