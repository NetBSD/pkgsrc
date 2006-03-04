# $NetBSD: Makefile,v 1.9 2006/03/04 21:29:10 jlam Exp $
#

DISTNAME=	p5-Palm-1.3.0
PKGREVISION=	2
SVR4_PKGNAME=	p5plm
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AR/ARENSB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.coldsync.org/
COMMENT=	Access Palm .pdb and .prc database files

WRKSRC=		${WRKDIR}/p5-Palm-1.003_000
PERL5_PACKLIST=	auto/Palm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
