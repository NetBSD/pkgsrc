# $NetBSD: Makefile,v 1.47 2021/05/24 19:50:10 wiz Exp $

DISTNAME=	Bit-Vector-7.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Bit-Vector
COMMENT=	Efficient base class implementing bit vectors
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp-Clan>=5.3:../../devel/p5-Carp-Clan
#DEPENDS+=	{perl>=5.12.0,p5-Storable>=2.21}:../../devel/p5-Storable

PERL5_PACKLIST=		auto/Bit/Vector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
