# $NetBSD: Makefile,v 1.2 2012/09/11 23:04:27 asau Exp $
#

DISTNAME=	Math-Random-MT-Auto-6.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Random-MT-Auto/
COMMENT=	Auto-seeded Mersenne Twister PRNGs
LICENSE=	modified-bsd

DEPENDS+=	p5-Object-InsideOut>=2.06:../../devel/p5-Object-InsideOut
DEPENDS+=	p5-Exception-Class>=1.22:../../devel/p5-Exception-Class
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Math/Random/MT/Auto/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
