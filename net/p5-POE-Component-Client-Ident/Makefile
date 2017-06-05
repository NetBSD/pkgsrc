# $NetBSD: Makefile,v 1.18 2017/06/05 14:24:23 ryoon Exp $
#

DISTNAME=	POE-Component-Client-Ident-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-Client-Ident/
COMMENT=	Non-blocking ident lookups to your sessions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-POE>=0.38:../../devel/p5-POE
BUILD_DEPENDS+=	p5-Test-POE-Server-TCP-[0-9]*:../../devel/p5-Test-POE-Server-TCP

PERL5_PACKLIST=		auto/POE/Component/Client/Ident/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
