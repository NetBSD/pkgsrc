# $NetBSD: Makefile,v 1.24 2021/05/24 19:50:17 wiz Exp $

DISTNAME=	Class-Inner-0.200001
PKGNAME=	p5-${DISTNAME:S/200001/200.001/}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Inner
COMMENT=	Perlish implementation of Java like inner classes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Inner/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
