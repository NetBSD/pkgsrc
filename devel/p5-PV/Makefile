# $NetBSD: Makefile,v 1.4 1998/11/19 15:40:45 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/06/24 18:43:28 jfitz Exp
#

DISTNAME=	perlvision
PKGNAME=	p5-PV-1.0
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PV
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

DEPENDS+=	p5-Curses-1.02:../../devel/p5-Curses

USE_PERL5=	YES

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKDIR}/PV.pm ${PREFIX}/lib/perl5/site_perl
	${INSTALL_DATA} ${WRKDIR}/PerlVision.doc ${PREFIX}/lib/perl5/site_perl

.include "../../mk/bsd.pkg.mk"
