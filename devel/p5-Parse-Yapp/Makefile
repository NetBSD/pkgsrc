# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:18 veego Exp $
#

DISTNAME=      	Parse-Yapp-1.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p6pya
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 LALR parser

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Parse/Yapp/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
