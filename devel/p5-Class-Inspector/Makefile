# $NetBSD: Makefile,v 1.30 2019/08/11 13:19:01 wiz Exp $

DISTNAME=	Class-Inspector-1.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Inspector
COMMENT=	Provides information about Classes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Inspector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
