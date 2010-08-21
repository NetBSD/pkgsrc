# $NetBSD: Makefile,v 1.4 2010/08/21 16:35:11 seb Exp $
#

DISTNAME=		Math-BigInt-GMP-1.24
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Math-BigInt-GMP/
COMMENT=		Perl 5 module for arbitrary size integer math via the GMP library
LICENSE=		gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Math/BigInt/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
