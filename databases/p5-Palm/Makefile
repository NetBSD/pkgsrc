# $NetBSD: Makefile,v 1.4 2004/12/20 11:30:57 grant Exp $
#

DISTNAME=	p5-Palm-1.3.0
SVR4_PKGNAME=	p5plm
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AR/ARENSB/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ooblick.com/software/coldsync/
COMMENT=	Access Palm .pdb and .prc database files

WRKSRC=		${WRKDIR}/p5-Palm-1.003_000
USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Palm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
