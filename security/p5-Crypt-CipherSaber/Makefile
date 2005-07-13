# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:38 jlam Exp $
#

DISTNAME=		CipherSaber-0.60
PKGNAME=		p5-Crypt-${DISTNAME}
SVR4_PKGNAME=		p5ccs
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CipherSaber/
COMMENT=		Perl5 module for the CipherSaber encryptions

PERL5_PACKLIST=		auto/Crypt/CipherSaber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
