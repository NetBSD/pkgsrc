# $NetBSD: Makefile,v 1.7 2011/08/16 22:21:45 wiz Exp $
#

DISTNAME=		Math-BigInt-GMP-1.36
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Math-BigInt-GMP/
COMMENT=		Perl 5 module for arbitrary size integer math via the GMP library
LICENSE=		${PERL5_LICENSE}

PERL5_REQD+=		5.14.1 # for Math::BigInt 1.994

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Math/BigInt/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
