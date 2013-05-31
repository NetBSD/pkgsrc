# $NetBSD: Makefile,v 1.16 2013/05/31 12:41:57 wiz Exp $
#

DISTNAME=		Net-OpenSSH-0.57
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
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
