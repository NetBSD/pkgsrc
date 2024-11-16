# $NetBSD: Makefile,v 1.28 2024/11/16 12:06:19 wiz Exp $
#

DISTNAME=	POE-Component-Client-Ident-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/POE-Component-Client-Ident
COMMENT=	Non-blocking ident lookups to your sessions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-POE>=0.38:../../devel/p5-POE
TOOL_DEPENDS+=	p5-Test-POE-Server-TCP-[0-9]*:../../devel/p5-Test-POE-Server-TCP

PERL5_PACKLIST=		auto/POE/Component/Client/Ident/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
