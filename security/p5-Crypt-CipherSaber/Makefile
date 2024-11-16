# $NetBSD: Makefile,v 1.28 2024/11/16 12:06:27 wiz Exp $
#

DISTNAME=		Crypt-CipherSaber-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		10
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CipherSaber
COMMENT=		Perl5 module for the CipherSaber encryptions

PERL5_PACKLIST=		auto/Crypt/CipherSaber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
