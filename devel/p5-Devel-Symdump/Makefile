# $NetBSD: Makefile,v 1.1.1.1 1999/12/06 08:34:24 rh Exp $
#

DISTNAME=	Devel-Symdump-2.00
PKGNAME=	p5-Devel-Symdump-2.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
