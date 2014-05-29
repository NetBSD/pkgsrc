# $NetBSD: Makefile,v 1.15 2014/05/29 23:37:21 wiz Exp $
#

DISTNAME=		Crypt-CipherSaber-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
SVR4_PKGNAME=		p5ccs
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CipherSaber/
COMMENT=		Perl5 module for the CipherSaber encryptions

PERL5_PACKLIST=		auto/Crypt/CipherSaber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
