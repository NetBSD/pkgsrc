# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:37 jlam Exp $
#

DISTNAME=	NetAddr-IP-3.24
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nai
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetAddr/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://mipagina.cantv.net/lem/perl/iptut.html
COMMENT=	Perl5 module for managing IP addresses

# This is for the 'test' target
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Module-Signature-[0-9]*:../../security/p5-Module-Signature

PERL5_REQD=		5.6.0
USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/NetAddr/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
