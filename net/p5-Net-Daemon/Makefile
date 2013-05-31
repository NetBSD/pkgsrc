# $NetBSD: Makefile,v 1.28 2013/05/31 12:41:37 wiz Exp $
#

DISTNAME=	Net-Daemon-0.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5nda
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Daemon/
COMMENT=	Perl5 module for writing networking daemons
LICENSE=	${PERL5_LICENSE}

#WRKSRC=		${WRKDIR}/Net-Daemon/

PERL5_PACKLIST=		auto/Net/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
