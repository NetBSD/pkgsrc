# $NetBSD: Makefile,v 1.5 2004/12/20 11:31:06 grant Exp $
#

DISTNAME=	INET6-2.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://search.cpan.org/~mondejar/INET6/
COMMENT=	Object interface for AF_INET|AF_INET6 domain sockets

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IO/Socket/INET6/.packlist

.include "../../net/p5-Socket6/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
