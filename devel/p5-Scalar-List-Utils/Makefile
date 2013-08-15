# $NetBSD: Makefile,v 1.25 2013/08/15 02:43:24 wen Exp $
#

DISTNAME=		Scalar-List-Utils-1.31
PKGNAME=		p5-${DISTNAME}
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
