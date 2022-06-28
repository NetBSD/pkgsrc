# $NetBSD: Makefile,v 1.13 2022/06/28 11:35:09 wiz Exp $

DISTNAME=	Net-Domain-TLD-1.75
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Domain-TLD
COMMENT=	Work with TLD names
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Net/Domain/TLD/.packlist
#USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
