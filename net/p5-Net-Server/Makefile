# $NetBSD: Makefile,v 1.31 2013/06/16 19:21:27 sno Exp $
#

DISTNAME=	Net-Server-2.007
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nts
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seamons.com/net_server.html
COMMENT=	Perl5 modules for network services engine
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL=	bin/net-server

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
