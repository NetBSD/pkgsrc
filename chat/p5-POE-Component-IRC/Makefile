# $NetBSD: Makefile,v 1.30 2019/06/30 20:14:15 nia Exp $

DISTNAME=	POE-Component-IRC-6.90
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/POE-Component-IRC
COMMENT=	Fully event-driven IRC client module
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-POE>=1.311:../../devel/p5-POE
DEPENDS+=	p5-IRC-Utils>=0.12:../../chat/p5-IRC-Utils
DEPENDS+=	p5-POE-Component-Syndicator-[0-9]*:../../devel/p5-POE-Component-Syndicator
DEPENDS+=	p5-POE-Filter-IRCD>=2.42:../../chat/p5-POE-Filter-IRCD
DEPENDS+=	p5-Test-Differences>=0.61:../../devel/p5-Test-Differences

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_PACKLIST=		auto/POE/Component/IRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
