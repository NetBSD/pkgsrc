# $NetBSD: Makefile,v 1.39 2021/09/12 07:48:12 wen Exp $
#

DISTNAME=	Net-Daemon-0.49
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Daemon
COMMENT=	Perl5 module for writing networking daemons
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
