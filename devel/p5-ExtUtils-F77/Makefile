# $NetBSD: Makefile,v 1.1.1.1 2000/11/26 22:08:06 jtb Exp $

DISTNAME=	ExtUtils-F77-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	jtb@netbsd.org

USE_PERL5=	#defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/ExtUtils/F77/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

