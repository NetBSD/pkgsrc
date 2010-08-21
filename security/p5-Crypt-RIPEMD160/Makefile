# $NetBSD: Makefile,v 1.17 2010/08/21 16:35:40 seb Exp $
#

DISTNAME=		Crypt-RIPEMD160-0.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
SVR4_PKGNAME=		p5cri
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-RIPEMD160/
COMMENT=		Perl5 module of the RIPEMD160 hash function

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Crypt/RIPEMD160/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
