# $NetBSD: Makefile,v 1.6 2001/04/27 16:28:12 wiz Exp $
#

DISTNAME=      	TimeDate-1.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	packages@netbsd.org
COMMENT=	the perl5 TimeDate distribution

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/TimeDate/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
