# $NetBSD: Makefile,v 1.3 2000/08/27 07:11:03 jlam Exp $
#

DISTNAME=     	DateManip-5.37
PKGNAME=       	p5-Date-Manip-5.37
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.cpan.org/

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Date/Manip/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
