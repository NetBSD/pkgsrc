# $NetBSD: Makefile,v 1.25 2018/08/22 09:46:53 wiz Exp $

DISTNAME=	Pod-Coverage-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Coverage/
COMMENT=	Checks if the documentation of a module is comprehensive
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-Symdump>=2.01:../../devel/p5-Devel-Symdump

PERL5_PACKLIST=		auto/Pod/Coverage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
