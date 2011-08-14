# $NetBSD: Makefile,v 1.10 2011/08/14 14:14:47 obache Exp $

DISTNAME=	Net-XWhois-0.90
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-XWhois/
COMMENT=	Perl5 module for Whois Client Interface

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/XWhois/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
