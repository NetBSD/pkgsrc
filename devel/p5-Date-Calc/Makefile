# $NetBSD: Makefile,v 1.13 2004/04/25 04:07:45 minskim Exp $
#

DISTNAME=     	Date-Calc-5.3
PKGNAME=       	p5-${DISTNAME}
SVR4_PKGNAME=	p5dca
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.engelschall.com/u/sb/download/
COMMENT=	Perl5 module for Gregorian calendar date calculations

DEPENDS+=	p5-Bit-Vector-[0-9]*:../../devel/p5-Bit-Vector

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Date/Calc/.packlist

post-patch:
	@rm -rf ${WRKSRC}/lib/Carp

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
