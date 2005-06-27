# $NetBSD: Makefile,v 1.12.2.1 2005/06/27 13:18:52 salo Exp $
#

DISTNAME=	Net-Server-0.88
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nts
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://seamons.com/net_server.html
COMMENT=	Perl5 modules for network services engine

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
