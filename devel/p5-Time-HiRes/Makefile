# $NetBSD: Makefile,v 1.7 2001/11/26 06:49:55 jlam Exp $
#

DISTNAME=		Time-HiRes-01.20
PKGNAME=		p5-Time-HiRes-01.20
SVR4_PKGNAME=		p5thr
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		bad@netbsd.org
COMMENT=		perl5 module for high resolution time, sleep, and alarm

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time/HiRes/.packlist

WRKSRC=			${WRKDIR}/Time-HiRes-01.20

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
