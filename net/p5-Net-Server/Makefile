# $NetBSD: Makefile,v 1.3 2003/06/02 01:17:49 jschauma Exp $
#

DISTNAME=	Net-Server-0.84
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5net
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://seamons.com/net_server.html
COMMENT=	perl5 modules for network services engine

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
