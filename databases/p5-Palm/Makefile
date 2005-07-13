# $NetBSD: Makefile,v 1.7 2005/07/13 18:01:21 jlam Exp $
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
PERL5_PACKLIST=	auto/Palm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
