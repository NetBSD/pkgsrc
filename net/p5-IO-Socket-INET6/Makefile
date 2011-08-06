# $NetBSD: Makefile,v 1.10 2011/08/06 10:54:25 tron Exp $

DISTNAME=		IO-Socket-INET6-2.67
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Socket-INET6/
COMMENT=		Perl object interface for AF_INET|AF_INET6 domain sockets
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Socket6>=0.12:../../net/p5-Socket6

SUPERSEDES=		p5-INET6-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IO/Socket/INET6/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
