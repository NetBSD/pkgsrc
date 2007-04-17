# $NetBSD: Makefile,v 1.11 2007/04/17 22:52:04 joerg Exp $
#

DISTNAME=	INET6-2.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mondejar/INET6/
COMMENT=	Object interface for AF_INET and AF_INET6 domain sockets

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Socket6>=0.12:../../net/p5-Socket6

PERL5_PACKLIST=	auto/IO/Socket/INET6/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
