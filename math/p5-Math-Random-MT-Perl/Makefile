# $NetBSD: Makefile,v 1.5 2011/08/14 13:38:23 obache Exp $
#

DISTNAME=	Math-Random-MT-Perl-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Random-MT-Perl/
COMMENT=	Pure Perl Mersenne Twister Random Number Generator 
LICENSE=	artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Math/Random/MT/Perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
