# $NetBSD: Makefile,v 1.2 1999/12/28 05:34:23 wiz Exp $
#

DISTNAME=      	TimeDate-1.08
PKGNAME=	${DISTNAME:S/^/p5-/}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
