# $NetBSD: Makefile,v 1.3 2005/10/14 09:46:54 adrianp Exp $
#

DISTNAME=	POE-Component-IRC-4.71
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bingos/${DISTNAME}/
COMMENT=	Fully event-driven IRC client module.

DEPENDS+=	p5-POE>=0.17:../../devel/p5-POE
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-POE-Component-Client-DNS-[0-9]*:../../net/p5-POE-Component-Client-DNS
DEPENDS+=	p5-POE-Component-Client-Ident-[0-9]*:../../net/p5-POE-Component-Client-Ident
DEPENDS+=	p5-POE-Filter-IRCD-[0-9]*:../../chat/p5-POE-Filter-IRCD

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/POE/Component/IRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
