# $NetBSD: Makefile,v 1.3 2004/12/20 11:31:02 grant Exp $
#

DISTNAME=		Scalar-List-Utils-1.13
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5slu
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Scalar/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/search?dist=Scalar-List-Utils
COMMENT=		Perl subroutines that would be nice to have in the perl core

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/List/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
