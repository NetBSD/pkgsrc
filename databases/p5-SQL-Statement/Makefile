# $NetBSD: Makefile,v 1.4 2001/05/26 01:49:12 mjl Exp $
#

DISTNAME=	SQL-Statement-0.1020
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	http://
COMMENT=	small, abstract SQL engine

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/SQL/Statement/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
