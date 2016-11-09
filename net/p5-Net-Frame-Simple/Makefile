# $NetBSD: Makefile,v 1.10 2016/11/09 13:48:50 mef Exp $

DISTNAME=	Net-Frame-Simple-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Frame crafting made easy
HOMEPAGE=	http://search.cpan.org/dist/Net-Frame-Simple/
LICENSE=	artistic

DEPENDS+=	p5-Class-Gomor>=1.0:../../devel/p5-Class-Gomor
DEPENDS+=	p5-Net-Frame-[0-9]*:../../net/p5-Net-Frame

PERL5_PACKLIST=		auto/Net/Frame/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
