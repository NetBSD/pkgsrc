# $NetBSD: Makefile,v 1.1.1.1 2001/04/16 17:40:41 jtb Exp $
#

DISTNAME=       Pod-POM-0.02
PKGNAME=        p5-${DISTNAME}
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
