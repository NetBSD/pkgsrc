# $NetBSD: Makefile,v 1.1.1.1 1999/12/03 08:47:25 rh Exp $
#

PKGNAME=       	p5-TimeDate-1.08
DISTNAME!=     	echo ${PKGNAME} | sed -e 's/^p5-//'
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
