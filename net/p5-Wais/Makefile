# $NetBSD: Makefile,v 1.1.1.1 1999/05/11 14:03:13 bad Exp $
#

DISTNAME=	Wais-2.311
PKGNAME=	p5-Wais-2.311
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wais/}

MAINTAINER=	bad@netbsd.org

DEPENDS+=	freewais-sf-2.2.12:../../test/freewais-sf
DEPENDS+=	p5-Curses-1.02:../../devel/p5-Curses

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
