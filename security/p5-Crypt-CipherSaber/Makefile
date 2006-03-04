# $NetBSD: Makefile,v 1.6 2006/03/04 21:30:36 jlam Exp $
#

DISTNAME=		CipherSaber-0.60
PKGNAME=		p5-Crypt-${DISTNAME}
SVR4_PKGNAME=		p5ccs
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CipherSaber/
COMMENT=		Perl5 module for the CipherSaber encryptions

PERL5_PACKLIST=		auto/Crypt/CipherSaber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
