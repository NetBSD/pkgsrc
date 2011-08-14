# $NetBSD: Makefile,v 1.9 2011/08/14 14:14:48 obache Exp $
#

DISTNAME=	POE-Component-Client-DNS-1.051
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-Client-DNS/
COMMENT=	Non-blocking, concurrent DNS requests
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-POE>=1.28:../../devel/p5-POE
DEPENDS+=	p5-Net-DNS>=0.59:../../net/p5-Net-DNS
DEPENDS+=	p5-Test-NoWarnings>=0.084:../../devel/p5-Test-NoWarnings

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/POE/Component/Client/DNS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
