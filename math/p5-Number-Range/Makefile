# $NetBSD: Makefile,v 1.7 2018/08/22 09:45:40 wiz Exp $

DISTNAME=		Number-Range-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Number-Range/
COMMENT=		Define ranges and test if number is in range
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Range/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
