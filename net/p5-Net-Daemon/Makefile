# $NetBSD: Makefile,v 1.40 2022/06/28 11:35:09 wiz Exp $
#

DISTNAME=	Net-Daemon-0.49
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Daemon
COMMENT=	Perl5 module for writing networking daemons
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
