# $NetBSD: Makefile,v 1.15 2012/10/02 21:25:33 asau Exp $

DISTNAME=	p5-Palm-1.012
PKGNAME=	${DISTNAME:S/012/12.0/}
PKGREVISION=	2
SVR4_PKGNAME=	p5plm
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BD/BDFOY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.coldsync.org/
COMMENT=	Access Palm .pdb and .prc database files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Palm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
