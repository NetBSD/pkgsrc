# $NetBSD: Makefile,v 1.44 2021/09/05 08:04:17 wen Exp $

DISTNAME=	Net-Server-2.010
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://seamons.com/net_server.html
COMMENT=	Perl5 modules for network services engine
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL=	bin/net-server

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
