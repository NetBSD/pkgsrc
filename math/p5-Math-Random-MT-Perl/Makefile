# $NetBSD: Makefile,v 1.1.1.1 2008/07/26 20:09:16 he Exp $
#

DISTNAME=	Math-Random-MT-Perl-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Random-MT-Perl/
COMMENT=	Pure Perl Mersenne Twister Random Number Generator 

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Math/Random/MT/Perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
