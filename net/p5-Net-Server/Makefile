# $NetBSD: Makefile,v 1.2 2003/04/16 18:04:48 jmc Exp $
#

DISTNAME=	Net-Server-0.84
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5net
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://seamons.com/net_server.html
COMMENT=	perl5 modules for network services engine

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
