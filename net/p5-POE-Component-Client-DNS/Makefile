# $NetBSD: Makefile,v 1.5 2008/10/19 19:18:33 he Exp $
#

DISTNAME=	POE-Component-Client-DNS-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-Client-DNS/
COMMENT=	Non-blocking, concurrent DNS requests

DEPENDS+=	p5-POE>=0.31:../../devel/p5-POE
DEPENDS+=	p5-Net-DNS>=0.59:../../net/p5-Net-DNS

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/POE/Component/Client/DNS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
