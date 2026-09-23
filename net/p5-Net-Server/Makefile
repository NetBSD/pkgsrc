# $NetBSD: Makefile,v 1.56 2026/09/23 22:04:19 wiz Exp $

DISTNAME=	Net-Server-2.018
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BB/BBB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://seamons.com/projects/
COMMENT=	Perl5 modules for network services engine
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Socket-INET6>=0:../../net/p5-IO-Socket-INET6

REPLACE_PERL=	bin/net-server

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
