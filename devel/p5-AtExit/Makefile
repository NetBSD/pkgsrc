# $NetBSD: Makefile,v 1.3 2000/08/27 07:11:01 jlam Exp $
#

DISTNAME=	AtExit-2.01
PKGNAME=	p5-AtExit-2.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AtExit/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_ARCHLIB}/auto/AtExit/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
