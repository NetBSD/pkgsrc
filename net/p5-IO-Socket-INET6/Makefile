# $NetBSD: Makefile,v 1.1.1.1 2008/11/05 15:20:39 wiz Exp $
#

DISTNAME=		IO-Socket-INET6-2.56
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Socket-INET6/
COMMENT=		Perl object interface for AF_INET|AF_INET6 domain sockets

DEPENDS+=		p5-Socket6-[0-9]*:../../net/p5-Socket6

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IO/Socket/INET6/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
