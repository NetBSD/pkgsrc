# $NetBSD: Makefile,v 1.2 2003/12/17 14:22:30 martti Exp $
#

DISTNAME=	INET6-2.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	wip perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://search.cpan.org/~mondejar/INET6/
COMMENT=	Object interface for AF_INET|AF_INET6 domain sockets

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IO/Socket/INET6/.packlist

.include "../../net/p5-Socket6/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
