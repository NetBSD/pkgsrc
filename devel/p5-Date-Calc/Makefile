# $NetBSD: Makefile,v 1.34 2013/05/31 12:40:14 wiz Exp $

DISTNAME=	Date-Calc-6.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5dca
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://engelschall.com/u/sb/download/
COMMENT=	Perl5 module for Gregorian calendar date calculations
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Bit-Vector>=7.1:../../devel/p5-Bit-Vector
DEPENDS+=	p5-Carp-Clan>=6.04:../../devel/p5-Carp-Clan

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Date/Calc/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
