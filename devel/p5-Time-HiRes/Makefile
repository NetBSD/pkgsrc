# $NetBSD: Makefile,v 1.6 2001/10/18 15:20:20 veego Exp $
#

DISTNAME=		Time-HiRes-01.20
PKGNAME=		p5-Time-HiRes-01.20
SVR4_PKGNAME=		p5thr
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		bad@netbsd.org
COMMENT=		perl5 module for high resolution time, sleep, and alarm

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time/HiRes/.packlist

WRKSRC=			${WRKDIR}/Time-HiRes-01.20

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
