# $NetBSD: Makefile,v 1.3 2000/08/27 07:11:08 jlam Exp $
#

DISTNAME=		Time-HiRes-01.19
PKGNAME=		p5-Time-HiRes-01.19
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		bad@netbsd.org

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time/HiRes/.packlist

WRKSRC=			${WRKDIR}/Time-HiRes-01.19

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
