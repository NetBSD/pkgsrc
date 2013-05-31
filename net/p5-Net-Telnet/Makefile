# $NetBSD: Makefile,v 1.25 2013/05/31 12:41:40 wiz Exp $
#

DISTNAME=	Net-Telnet-3.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
SVR4_PKGNAME=	p5nte
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Telnet
COMMENT=	Perl5 module to use telnet
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Telnet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
