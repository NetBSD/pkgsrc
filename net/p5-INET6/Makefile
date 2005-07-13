# $NetBSD: Makefile,v 1.8 2005/07/13 18:01:35 jlam Exp $
#

DISTNAME=	INET6-2.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mondejar/INET6/
COMMENT=	Object interface for AF_INET|AF_INET6 domain sockets

PERL5_PACKLIST=	auto/IO/Socket/INET6/.packlist

.include "../../net/p5-Socket6/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
