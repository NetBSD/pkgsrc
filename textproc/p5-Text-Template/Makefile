# $NetBSD: Makefile,v 1.3 2001/02/17 17:37:38 wiz Exp $
#

DISTNAME=       Text-Template-1.23
PKGNAME=        p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.plover.com/~mjd/perl/Template/
COMMENT=	perl5 library for generating form letters

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/Template/.packlist

do-configure:
	@cd ${WRKSRC} && ${ECHO} >.test && \
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
