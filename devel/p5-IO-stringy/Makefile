# $NetBSD: Makefile,v 1.2 1999/12/28 05:33:01 wiz Exp $
#

DISTNAME=	IO-stringy-1.207
PKGNAME=        ${DISTNAME:S/^/p5-/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
