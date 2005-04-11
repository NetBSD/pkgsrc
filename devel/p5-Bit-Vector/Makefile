# $NetBSD: Makefile,v 1.17 2005/04/11 21:45:29 tv Exp $
#

DISTNAME=	Bit-Vector-6.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5biv
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Bit-Vector/
COMMENT=	Efficient base class implementing bit vectors

DEPENDS+=	p5-Carp-Clan-[0-9]*:../../devel/p5-Carp-Clan

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Bit/Vector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
