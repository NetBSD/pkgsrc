# $NetBSD: Makefile,v 1.16 2019/08/11 13:22:20 wiz Exp $

DISTNAME=	Net-INET6Glue-0.603
PKGNAME=	p5-${DISTNAME:S/603/6.3/}
PKGREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/modules\/by-module\//authors\/id\/S\/SU\/SULLR\//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-INET6Glue
COMMENT=	Make common Perl modules IPv6 ready by hotpatching
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-IO-Socket-INET6>=2.54:../../net/p5-IO-Socket-INET6

PERL5_PACKLIST=		auto/Net/INET6Glue/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
