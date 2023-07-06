# $NetBSD: Makefile,v 1.39 2023/07/06 09:41:11 wiz Exp $
#

DISTNAME=	Net-Telnet-3.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Telnet
COMMENT=	Perl5 module to use telnet
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Telnet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
