# $NetBSD: Makefile,v 1.1.1.1 2005/07/14 23:01:23 adrianp Exp $
#

DISTNAME=	POE-Component-Client-DNS-0.98
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rcaputo/POE-Component-Client-DNS-0.98/
COMMENT=	Non-blocking, concurrent DNS requests

DEPENDS+=	p5-POE-[0-9]*:../../devel/p5-POE
DEPENDS+=	p5-Net-DNS>=0.12:../../net/p5-Net-DNS

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_REQD+=		5.8.0
PERL5_PACKLIST=		auto/POE/Component/Client/DNS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
