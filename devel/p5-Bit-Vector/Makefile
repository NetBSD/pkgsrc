# $NetBSD: Makefile,v 1.9 2003/03/16 15:39:05 mjl Exp $
#

DISTNAME=	Bit-Vector-6.3
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5biv
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Bit-Vector/Vector.html
COMMENT=	Efficient base class implementing bit vectors

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Bit/Vector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
