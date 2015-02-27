# $NetBSD: Makefile,v 1.28 2015/02/27 14:39:24 mef Exp $
#

DISTNAME=	Net-Telnet-3.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Telnet
COMMENT=	Perl5 module to use telnet
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Telnet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
