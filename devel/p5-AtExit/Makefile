# $NetBSD: Makefile,v 1.1.1.1 1999/05/12 18:55:00 bad Exp $
#

DISTNAME=	AtExit-2.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AtExit/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	yes

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
