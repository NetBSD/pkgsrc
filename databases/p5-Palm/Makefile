# $NetBSD: Makefile,v 1.6 2005/04/11 21:45:13 tv Exp $
#

DISTNAME=	p5-Palm-1.3.0
PKGREVISION=	1
SVR4_PKGNAME=	p5plm
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AR/ARENSB/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.coldsync.org/
COMMENT=	Access Palm .pdb and .prc database files

WRKSRC=		${WRKDIR}/p5-Palm-1.003_000
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Palm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
