# $NetBSD: Makefile,v 1.12 2023/07/06 09:41:15 wiz Exp $

DISTNAME=	Test-RequiresInternet-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-RequiresInternet
COMMENT=	Test::RequiresInternet - Easily test network connectivity
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Test/RequiresInternet/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
