# $NetBSD: Makefile,v 1.54 2026/02/22 07:33:23 wiz Exp $

DISTNAME=	Net-Server-2.018
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
