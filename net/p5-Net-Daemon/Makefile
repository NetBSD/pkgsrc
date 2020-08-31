# $NetBSD: Makefile,v 1.37 2020/08/31 18:10:42 wiz Exp $
#

DISTNAME=	Net-Daemon-0.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Daemon
COMMENT=	Perl5 module for writing networking daemons
LICENSE=	${PERL5_LICENSE}

#WRKSRC=		${WRKDIR}/Net-Daemon/

PERL5_PACKLIST=		auto/Net/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
