# $NetBSD: Makefile,v 1.35 2023/07/06 09:38:46 wiz Exp $

DISTNAME=	Class-Inspector-1.36
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Inspector
COMMENT=	Provides information about Classes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Inspector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
