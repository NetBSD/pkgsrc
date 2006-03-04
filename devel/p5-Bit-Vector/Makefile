# $NetBSD: Makefile,v 1.20 2006/03/04 21:29:19 jlam Exp $
#

DISTNAME=	Bit-Vector-6.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5biv
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Bit-Vector/
COMMENT=	Efficient base class implementing bit vectors

DEPENDS+=	p5-Carp-Clan-[0-9]*:../../devel/p5-Carp-Clan

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Bit/Vector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
