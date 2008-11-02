# $NetBSD: Makefile,v 1.13 2008/11/02 21:39:52 seb Exp $
#

DISTNAME=	NetAddr-IP-4.014
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nai
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetAddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/NetAddr-IP/
COMMENT=	Perl5 module for managing IP addresses

PKG_DESTDIR_SUPPORT=	user-destdir

# This is for the 'test' target
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/NetAddr/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
