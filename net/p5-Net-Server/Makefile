# $NetBSD: Makefile,v 1.52 2026/02/01 07:40:18 wiz Exp $

DISTNAME=	Net-Server-2.016
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BB/BBB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://seamons.com/projects/
COMMENT=	Perl5 modules for network services engine
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL=	bin/net-server

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
