# $NetBSD: Makefile,v 1.27 2017/06/05 14:22:19 ryoon Exp $
#

DISTNAME=	POE-Component-IRC-6.88
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-IRC/
COMMENT=	Fully event-driven IRC client module
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-POE>=1.311:../../devel/p5-POE
DEPENDS+=	p5-IRC-Utils>=0.12:../../chat/p5-IRC-Utils
DEPENDS+=	p5-POE-Component-Syndicator-[0-9]*:../../devel/p5-POE-Component-Syndicator
DEPENDS+=	p5-POE-Filter-IRCD>=2.42:../../chat/p5-POE-Filter-IRCD
DEPENDS+=	p5-Test-Differences>=0.61:../../devel/p5-Test-Differences

PERL5_PACKLIST=		auto/POE/Component/IRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
