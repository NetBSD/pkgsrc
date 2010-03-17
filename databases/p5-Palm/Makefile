# $NetBSD: Makefile,v 1.12 2010/03/17 00:01:19 sno Exp $
#

DISTNAME=	p5-Palm-1.012
PKGNAME=	${DISTNAME:S/012/12.0/}
#PKGREVISION=	3
SVR4_PKGNAME=	p5plm
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BD/BDFOY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.coldsync.org/
COMMENT=	Access Palm .pdb and .prc database files
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

#WRKSRC=		${WRKDIR}/p5-Palm-1.003_000
PERL5_PACKLIST=	auto/Palm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
