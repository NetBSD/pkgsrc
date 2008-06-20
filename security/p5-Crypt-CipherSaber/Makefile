# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:34 joerg Exp $
#

DISTNAME=		Crypt-CipherSaber-1.00
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ccs
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CipherSaber/
COMMENT=		Perl5 module for the CipherSaber encryptions

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Crypt/CipherSaber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
