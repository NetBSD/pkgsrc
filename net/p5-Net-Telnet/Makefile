# $NetBSD: Makefile,v 1.33 2019/06/30 20:16:32 nia Exp $
#

DISTNAME=	Net-Telnet-3.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Telnet
COMMENT=	Perl5 module to use telnet
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Telnet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
