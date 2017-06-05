# $NetBSD: Makefile,v 1.23 2017/06/05 14:24:34 ryoon Exp $
#

DISTNAME=		Net-OpenSSH-0.74
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
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
