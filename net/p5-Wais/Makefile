# $NetBSD: Makefile,v 1.3 2000/08/27 07:11:18 jlam Exp $
#

DISTNAME=	Wais-2.311
PKGNAME=	p5-Wais-2.311
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wais/}

MAINTAINER=	bad@netbsd.org

DEPENDS+=	freewais-sf-2.2.12:../../net/freewais-sf
DEPENDS+=	p5-Curses-1.02:../../devel/p5-Curses

USE_PERL5=	# defined
PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Wais/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
