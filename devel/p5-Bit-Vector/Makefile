# $NetBSD: Makefile,v 1.14 2004/12/20 11:30:58 grant Exp $
#

DISTNAME=	Bit-Vector-6.4
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5biv
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Bit-Vector/Vector.html
COMMENT=	Efficient base class implementing bit vectors

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Bit/Vector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
