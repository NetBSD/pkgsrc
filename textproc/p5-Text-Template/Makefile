# $NetBSD: Makefile,v 1.1.1.1 2000/10/16 09:57:50 rh Exp $
#

DISTNAME=       Text-Template-1.23
PKGNAME=        p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.plover.com/~mjd/perl/Template/

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IMAP/Admin/.packlist

do-configure:
	@cd ${WRKSRC} && ${ECHO} >.test && \
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
