# $NetBSD: Makefile,v 1.17 2015/02/21 12:27:59 mef Exp $
#

DISTNAME=	Net-Gnats-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnatsperl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnatsperl.sourceforge.net/
#HOMEPAGE=	http://search.cpan.org/dist/Net-Gnats/
COMMENT=	Perl interface to the gnatsd daemon
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Gnats/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
