# $NetBSD: Makefile,v 1.10 2003/06/02 01:20:33 jschauma Exp $
#

DISTNAME=     	Date-Calc-5.3
PKGNAME=       	p5-${DISTNAME}
SVR4_PKGNAME=	p5dca
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.engelschall.com/u/sb/download/
COMMENT=	perl5 module for Gregorian calendar date calculations

DEPENDS+=	p5-Bit-Vector-[0-9]*:../../devel/p5-Bit-Vector

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Date/Calc/.packlist

post-patch:
	@rm -rf ${WRKSRC}/lib/Carp

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
