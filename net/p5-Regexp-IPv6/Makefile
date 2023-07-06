# $NetBSD: Makefile,v 1.13 2023/07/06 09:41:14 wiz Exp $
#

DISTNAME=	Regexp-IPv6-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Regexp-IPv6
COMMENT=	Regular expression for IPv6 addresses
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Regexp/IPv6/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
