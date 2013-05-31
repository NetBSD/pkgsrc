# $NetBSD: Makefile,v 1.22 2013/05/31 12:41:54 wiz Exp $
#

DISTNAME=		Crypt-RIPEMD160-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5cri
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-RIPEMD160/
COMMENT=		Perl5 module of the RIPEMD160 hash function
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Crypt/RIPEMD160/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
