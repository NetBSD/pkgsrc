# $NetBSD: Makefile,v 1.3 2012/10/23 17:18:48 asau Exp $

DISTNAME=	Net-Frame-Simple-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Frame crafting made easy
HOMEPAGE=	http://search.cpan.org/dist/Net-Frame-Simple/
LICENSE=	artistic

DEPENDS+=	p5-Class-Gomor>=1.0:../../devel/p5-Class-Gomor
DEPENDS+=	p5-Net-Frame-[0-9]*:../../net/p5-Net-Frame

PKG_INSTALLATION_TYPES=		overwrite pkgviews

PERL5_PACKLIST=		auto/Net/Frame/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
