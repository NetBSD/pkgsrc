# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:42 veego Exp $
#

DISTNAME=       Pod-POM-0.02
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5pod
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	p5 module to format POD into an object format, hence POM

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Pod/POM/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
