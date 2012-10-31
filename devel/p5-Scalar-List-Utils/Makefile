# $NetBSD: Makefile,v 1.23 2012/10/31 11:18:55 asau Exp $
#

DISTNAME=		Scalar-List-Utils-1.25
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5slu
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Scalar/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Scalar-List-Utils/
COMMENT=		Perl subroutines that would be nice to have in the perl core
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/List/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
