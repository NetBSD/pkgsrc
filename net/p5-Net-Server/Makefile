# $NetBSD: Makefile,v 1.12 2005/04/11 21:46:56 tv Exp $
#

DISTNAME=	Net-Server-0.87
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nts
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://seamons.com/net_server.html
COMMENT=	Perl5 modules for network services engine

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
