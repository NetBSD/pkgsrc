# $NetBSD: Makefile,v 1.6 2003/09/16 13:45:45 xtraeme Exp $
#

DISTNAME=	Net-Server-0.85
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5net
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://seamons.com/net_server.html
COMMENT=	Perl5 modules for network services engine

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
