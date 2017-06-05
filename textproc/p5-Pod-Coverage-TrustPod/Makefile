# $NetBSD: Makefile,v 1.3 2017/06/05 14:24:43 ryoon Exp $

DISTNAME=	Pod-Coverage-TrustPod-0.100003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Coverage-TrustPod/
COMMENT=	Allow a module's pod to contain Pod::Coverage hints
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Pod-Coverage-[0-9]*:../../textproc/p5-Pod-Coverage
DEPENDS+=	p5-Pod-Eventual-[0-9]*:../../textproc/p5-Pod-Eventual

PERL5_PACKLIST=		auto/Pod/Coverage/TrustPod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
