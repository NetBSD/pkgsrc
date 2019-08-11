# $NetBSD: Makefile,v 1.28 2019/08/11 13:22:58 wiz Exp $

DISTNAME=		Net-OpenSSH-0.78
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Net-OpenSSH
COMMENT=		Perl SSH client package implemented on top of OpenSSH
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Net/OpenSSH/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
