# $NetBSD: Makefile,v 1.22 2023/05/20 07:36:03 wiz Exp $

DISTNAME=	Devel-Caller-2.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Caller
COMMENT=	Meatier versions of caller
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PadWalker>0.08:../../devel/p5-PadWalker

PERL5_PACKLIST=		auto/Devel/Caller/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
