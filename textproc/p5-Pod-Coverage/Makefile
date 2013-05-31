# $NetBSD: Makefile,v 1.17 2013/05/31 12:42:11 wiz Exp $

DISTNAME=	Pod-Coverage-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Coverage/
COMMENT=	Checks if the documentation of a module is comprehensive
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-Symdump>=2.01:../../devel/p5-Devel-Symdump

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Pod/Coverage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
