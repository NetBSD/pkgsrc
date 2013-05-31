# $NetBSD: Makefile,v 1.18 2013/05/31 12:40:07 wiz Exp $

DISTNAME=	Carp-Clan-6.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5ccl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Carp-Clan/
COMMENT=	Report errors from perspective of a "clan" of modules
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Carp/Clan/.packlist
MAKE_PARAMS+=		< /dev/null

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
