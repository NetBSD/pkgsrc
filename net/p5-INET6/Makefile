# $NetBSD: Makefile,v 1.12 2008/10/12 18:44:01 seb Exp $
#

DISTNAME=	IO-Socket-INET6-2.56
PKGNAME=	p5-INET6-2.56
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Socket-INET6/
COMMENT=	Object interface for AF_INET and AF_INET6 domain sockets

USE_LANGUAGES=	# empty
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Socket6>=0.12:../../net/p5-Socket6

PERL5_PACKLIST=	auto/IO/Socket/INET6/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
