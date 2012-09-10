# $NetBSD: Makefile,v 1.21 2012/09/10 14:25:44 sno Exp $
#

DISTNAME=		Scalar-List-Utils-1.25
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5slu
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Scalar/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Scalar-List-Utils/
COMMENT=		Perl subroutines that would be nice to have in the perl core
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/List/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
