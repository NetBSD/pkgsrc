# $NetBSD: Makefile,v 1.1.1.1 2001/04/16 18:46:29 jtb Exp $

DISTNAME=	AppConfig-1.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/ABW/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	perl5 module for parsing config files and command line arguments

USE_PERL5=	#defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/AppConfig/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
