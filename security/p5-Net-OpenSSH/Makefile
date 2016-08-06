# $NetBSD: Makefile,v 1.21 2016/08/06 01:40:34 mef Exp $
#

DISTNAME=		Net-OpenSSH-0.73
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-OpenSSH/
COMMENT=		Perl SSH client package implemented on top of OpenSSH
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Net/OpenSSH/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
