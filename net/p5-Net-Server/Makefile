# $NetBSD: Makefile,v 1.1.1.1 2003/04/13 15:45:49 cjep Exp $
#

DISTNAME=	Net-Server-0.84
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5net
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://seamons.com/net_server.html
COMMENT=	perl5 modules for network services engine

USE_BUILDLINK2_ONLY=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
