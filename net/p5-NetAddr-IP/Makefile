# $NetBSD: Makefile,v 1.8 2006/02/05 23:10:28 joerg Exp $
#

DISTNAME=	NetAddr-IP-3.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5nai
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetAddr/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mipagina.cantv.net/lem/perl/iptut.html
COMMENT=	Perl5 module for managing IP addresses

# This is for the 'test' target
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Module-Signature-[0-9]*:../../security/p5-Module-Signature

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/NetAddr/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
