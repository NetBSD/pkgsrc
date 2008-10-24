# $NetBSD: Makefile,v 1.1.1.1 2008/10/24 20:36:27 seb Exp $
#

DISTNAME=	Net-MAC-1.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-MAC/
COMMENT=	Perl 5 module for representing and manipulating MAC addresses

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/MAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
