# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:56 tv Exp $
#

DISTNAME=	NetAddr-IP-3.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nai
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetAddr/}

MAINTAINER=	seb@NetBSD.org
COMMENT=	Perl5 module for managing IP addresses

# This is for the 'test' target
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

PERL5_REQD=		5.6.0
USE_LANGUAGES=		# empty

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/NetAddr/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
