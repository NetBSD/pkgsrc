# $NetBSD: Makefile,v 1.8 2001/10/18 15:20:20 veego Exp $
#

DISTNAME=      	TimeDate-1.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tid
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 TimeDate distribution

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/TimeDate/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
