# $NetBSD: Makefile,v 1.23 2009/07/28 06:16:01 sno Exp $
#

DISTNAME=	Bit-Vector-6.6
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5biv
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Bit-Vector/
COMMENT=	Efficient base class implementing bit vectors
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Carp-Clan>=5.3:../../devel/p5-Carp-Clan
# Well - let's see if someone report errors without devel/p5-Storable installed

PERL5_PACKLIST=		auto/Bit/Vector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
