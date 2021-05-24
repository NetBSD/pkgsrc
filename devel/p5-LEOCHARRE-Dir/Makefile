# $NetBSD: Makefile,v 1.14 2021/05/24 19:50:55 wiz Exp $
#

DISTNAME=	LEOCHARRE-Dir-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/L/LE/LEOCHARRE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LEOCHARRE-Dir
COMMENT=	Subs for general directory needs
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/LEOCHARRE/Dir/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
