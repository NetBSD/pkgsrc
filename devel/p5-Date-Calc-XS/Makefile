# $NetBSD: Makefile,v 1.17 2019/08/11 13:19:13 wiz Exp $

DISTNAME=	Date-Calc-XS-6.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Date-Calc-XS
COMMENT=	XS wrapper and C library plug-in for Date::Calc
LICENSE=	${PERL5_LICENSE} OR gnu-lgpl-v2

DEPENDS+=	p5-Bit-Vector>=7.1:../../devel/p5-Bit-Vector
DEPENDS+=	p5-Carp-Clan>=5.3:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Date-Calc>=6.2:../../devel/p5-Date-Calc

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Date/Calc/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
