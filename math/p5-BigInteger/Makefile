# $NetBSD: Makefile,v 1.1.1.1 2001/02/10 04:12:39 jtb Exp $

DISTNAME=	Math-BigInteger-1.0
PKGNAME=	p5-BigInteger-1.0
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	jtb@netbsd.org

USE_PERL5=	#defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Math/BigInteger/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

