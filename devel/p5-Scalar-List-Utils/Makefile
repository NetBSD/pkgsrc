# $NetBSD: Makefile,v 1.10 2006/01/03 17:33:46 wiz Exp $
#

DISTNAME=		Scalar-List-Utils-1.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5slu
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Scalar/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Scalar-List-Utils/
COMMENT=		Perl subroutines that would be nice to have in the perl core

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/List/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
