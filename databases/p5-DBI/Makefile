# $NetBSD: Makefile,v 1.2 2000/05/11 18:37:06 christos Exp $
#

DISTNAME=	DBI-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.symbolstone.org/technology/perl/DBI/index.html

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
